/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#ifndef SC_VALIDAT_HXX
#define SC_VALIDAT_HXX

#include <bf_svtools/bf_solar.h>

#ifndef SC_CONDITIO_HXX
#include "conditio.hxx"
#endif
namespace binfilter {

class ScPatternAttr;
class ScTokenArray;

enum ScValidationMode
{
	SC_VALID_ANY,
	SC_VALID_WHOLE,
	SC_VALID_DECIMAL,
	SC_VALID_DATE,
	SC_VALID_TIME,
	SC_VALID_TEXTLEN,
	SC_VALID_LIST,
	SC_VALID_CUSTOM
};

enum ScValidErrorStyle
{
	SC_VALERR_STOP,
	SC_VALERR_WARNING,
	SC_VALERR_INFO,
	SC_VALERR_MACRO
};

//
//	Eintrag fuer Gueltigkeit (es gibt nur eine Bedingung)
//

class ScValidationData : public ScConditionEntry
{
	sal_uInt32			nKey;				// Index in Attributen

	ScValidationMode	eDataMode;
	BOOL				bShowInput;
	BOOL				bShowError;
	ScValidErrorStyle	eErrorStyle;
	String				aInputTitle;
	String				aInputMessage;
	String				aErrorTitle;
	String				aErrorMessage;

	BOOL				bIsUsed;			// temporaer beim Speichern


public:
			ScValidationData( ScValidationMode eMode, ScConditionMode eOper,
								const String& rExpr1, const String& rExpr2,
								ScDocument* pDocument, const ScAddress& rPos,
								BOOL bCompileEnglish = FALSE, BOOL bCompileXML = FALSE );
			ScValidationData( const ScValidationData& r );
			ScValidationData( ScDocument* pDocument, const ScValidationData& r );
			ScValidationData( SvStream& rStream, ScMultipleReadHeader& rHdr,
								ScDocument* pDocument );
			~ScValidationData();

	void			Store(SvStream& rStream, ScMultipleWriteHeader& rHdr) const;

	ScValidationData* Clone() const		// echte Kopie
					{ return new ScValidationData( GetDocument(), *this ); }
	ScValidationData* Clone(ScDocument* pNew) const
					{ return new ScValidationData( pNew, *this ); }

	void			ResetInput();
	void			ResetError();
	void			SetInput( const String& rTitle, const String& rMsg );
	void			SetError( const String& rTitle, const String& rMsg,
								ScValidErrorStyle eStyle );

	BOOL			GetInput( String& rTitle, String& rMsg ) const
						{ rTitle = aInputTitle; rMsg = aInputMessage; return bShowInput; }
	BOOL			GetErrMsg( String& rTitle, String& rMsg, ScValidErrorStyle& rStyle ) const;

	BOOL			HasErrMsg() const		{ return bShowError; }

	ScValidationMode GetDataMode() const	{ return eDataMode; }


	BOOL			IsDataValid( ScBaseCell* pCell, const ScAddress& rPos ) const;

					// TRUE -> Abbruch

	BOOL			IsEmpty() const;
	sal_uInt32		GetKey() const			{ return nKey; }
	void			SetKey(sal_uInt32 nNew)		{ nKey = nNew; }	// nur wenn nicht eingefuegt!

	void			SetUsed(BOOL bSet)		{ bIsUsed = bSet; }
	BOOL			IsUsed() const			{ return bIsUsed; }

	BOOL			EqualEntries( const ScValidationData& r ) const;	// fuer Undo

	//	sortiert (per PTRARR) nach Index
	//	operator== nur fuer die Sortierung
	BOOL operator ==( const ScValidationData& r ) const	{ return nKey == r.nKey; }
	BOOL operator < ( const ScValidationData& r ) const	{ return nKey <  r.nKey; }
};

//
//	Liste der Bedingungen:
//

typedef ScValidationData* ScValidationDataPtr;

SV_DECL_PTRARR_SORT(ScValidationEntries_Impl, ScValidationDataPtr,
						SC_COND_GROW, SC_COND_GROW)//STRIP008 ;

class ScValidationDataList : public ScValidationEntries_Impl
{
public:
		ScValidationDataList() {}
		ScValidationDataList(const ScValidationDataList& rList);
		~ScValidationDataList() {}

	void	InsertNew( ScValidationData* pNew )
				{ if (!Insert(pNew)) delete pNew; }

	ScValidationData* GetData( sal_uInt32 nKey );

	void	Load( SvStream& rStream, ScDocument* pDocument );
	void	Store( SvStream& rStream ) const;
	void	ResetUsed();

	void	CompileXML();

};

} //namespace binfilter
#endif


