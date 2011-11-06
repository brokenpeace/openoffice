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


#ifndef _SDYNITM_HXX
#define _SDYNITM_HXX

#include <bf_svtools/bf_solar.h>

#ifndef _SFXENUMITEM_HXX //autogen
#include <bf_svtools/eitem.hxx>
#endif
namespace binfilter {

//------------------------------------------------------------
// class SdrYesNoItem
// hier liefert GetValueTextByVal() "ja" oder "nein"
// anstelle von "TRUE" und "FALSE"
//------------------------------------------------------------
class SdrYesNoItem: public SfxBoolItem {
public:
	TYPEINFO();
	SdrYesNoItem(): SfxBoolItem() {}
	SdrYesNoItem(USHORT nId, BOOL bOn=FALSE): SfxBoolItem(nId,bOn) {}
	SdrYesNoItem(USHORT nId, SvStream& rIn):  SfxBoolItem(nId,rIn) {}
	virtual SfxPoolItem* Clone(SfxItemPool* pPool=NULL) const;
	virtual SfxPoolItem* Create(SvStream& rIn, USHORT nVer) const;
#ifdef SDR_ISPOOLABLE
	virtual int IsPoolable() const;
#endif
};

}//end of namespace binfilter
#endif
