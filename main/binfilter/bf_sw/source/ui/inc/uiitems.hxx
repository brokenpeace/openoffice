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


#ifndef _UIITEMS_HXX
#define _UIITEMS_HXX

#include <bf_svtools/bf_solar.h>

#include "pagedesc.hxx"
#include "cmdid.h"
#ifndef _SFXINTITEM_HXX
#include <bf_svtools/intitem.hxx>
#endif
class IntlWrapper; 
namespace binfilter {
class SwNumRule;


/*--------------------------------------------------------------------
	Beschreibung: Container fuer FootNote
 --------------------------------------------------------------------*/
class SwPageFtnInfoItem : public SfxPoolItem
{
	SwPageFtnInfo aFtnInfo;

public:

	SwPageFtnInfoItem(const USHORT nId, SwPageFtnInfo& rInfo);
	SwPageFtnInfoItem(const SwPageFtnInfoItem& rItem );
	~SwPageFtnInfoItem();

	virtual SfxPoolItem*    Clone( SfxItemPool *pPool = 0 ) const;
	virtual int             operator==( const SfxPoolItem& ) const;

    virtual BOOL             QueryValue( ::com::sun::star::uno::Any& rVal, BYTE nMemberId = 0 ) const;
	virtual	BOOL			 PutValue( const ::com::sun::star::uno::Any& rVal, BYTE nMemberId = 0 );

    SwPageFtnInfo& GetPageFtnInfo()             { return aFtnInfo; }
	const SwPageFtnInfo& GetPageFtnInfo() const { return aFtnInfo; }
	void SetPageFtnInfo(SwPageFtnInfo& rInf) 	{ aFtnInfo = rInf; }
};

/*******************************************************************/





/*******************************************************************/






/* -----------------17.06.98 17:40-------------------
 *
 * --------------------------------------------------*/


} //namespace binfilter
#endif // _UIITEMS_HXX
