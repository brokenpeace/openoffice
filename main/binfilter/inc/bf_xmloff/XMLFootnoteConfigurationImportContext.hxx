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



#ifndef _XMLOFF_XMLFOOTNOTECONFIGURATIONIMPORTCONTEXT_HXX
#define _XMLOFF_XMLFOOTNOTECONFIGURATIONIMPORTCONTEXT_HXX

#ifndef _XMLOFF_XMLSTYLE_HXX
#include "xmlstyle.hxx"
#endif

namespace com { namespace sun { namespace star {
	namespace uno {	template<class X> class Reference; }
	namespace xml { namespace sax { class XAttributeList; } }
	namespace beans { class XPropertySet; }
} } }
namespace rtl {	class OUString; }
namespace binfilter {
class SvXMLImport;

/// import footnote and endnote configuration elements
class XMLFootnoteConfigurationImportContext : public SvXMLStyleContext
{
	const ::rtl::OUString sPropertyAnchorCharStyleName;
	const ::rtl::OUString sPropertyCharStyleName;
	const ::rtl::OUString sPropertyNumberingType;
	const ::rtl::OUString sPropertyPageStyleName;
	const ::rtl::OUString sPropertyParagraphStyleName;
	const ::rtl::OUString sPropertyPrefix;
	const ::rtl::OUString sPropertyStartAt;
	const ::rtl::OUString sPropertySuffix;
	const ::rtl::OUString sPropertyPositionEndOfDoc;
	const ::rtl::OUString sPropertyFootnoteCounting;
	const ::rtl::OUString sPropertyEndNotice;
	const ::rtl::OUString sPropertyBeginNotice;

	::rtl::OUString sCitationStyle;
	::rtl::OUString sAnchorStyle;
	::rtl::OUString sDefaultStyle;
	::rtl::OUString sPageStyle;
	::rtl::OUString sPrefix;
	::rtl::OUString sSuffix;
	::rtl::OUString sNumFormat;
	::rtl::OUString sNumSync;
	::rtl::OUString sBeginNotice;
	::rtl::OUString sEndNotice;

	SvXMLTokenMap* pAttrTokenMap;

	sal_Int16 nOffset;
	sal_Int16 nNumbering;
	sal_Bool bPosition;
	sal_Bool bIsEndnote;

public:

	TYPEINFO();

	XMLFootnoteConfigurationImportContext( 
		SvXMLImport& rImport, 
		sal_uInt16 nPrfx,
		const ::rtl::OUString& rLName,
		const ::com::sun::star::uno::Reference<
				::com::sun::star::xml::sax::XAttributeList> & xAttrList,
		sal_Bool bEndnote);

	virtual ~XMLFootnoteConfigurationImportContext();

	/// parse attributes
	virtual void StartElement(
		const ::com::sun::star::uno::Reference<
			::com::sun::star::xml::sax::XAttributeList> & xAttrList );

	/// for footnotes, also parse begin and end notices
	virtual SvXMLImportContext *CreateChildContext( 
		USHORT nPrefix,
		const ::rtl::OUString& rLocalName,
		const ::com::sun::star::uno::Reference< 
			::com::sun::star::xml::sax::XAttributeList> & xAttrList );

	/// get token map for attributes
	const SvXMLTokenMap& GetFtnConfigAttrTokenMap();

	/// set configuration at document; calls ProcessSettings
	/// Uses CreateAndInsertLate() to ensure that all styles it references 
	/// have been set.
	virtual void CreateAndInsertLate( sal_Bool bOverwrite );

	/// set configuration at document
	void ProcessSettings(
		const ::com::sun::star::uno::Reference<
			::com::sun::star::beans::XPropertySet> & rConfig);

	/// for helper class: set begin notice
	void SetBeginNotice( ::rtl::OUString sText);

	/// for helper class: set end notice
	void SetEndNotice( ::rtl::OUString sText);
};

}//end of namespace binfilter
#endif
