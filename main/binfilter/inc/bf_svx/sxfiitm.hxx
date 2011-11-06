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


#ifndef _SFXIITM_HXX
#define _SFXIITM_HXX

#ifndef _SFXPOOLITEM_HXX //autogen
#include <bf_svtools/poolitem.hxx>
#endif

#ifndef _FRACT_HXX //autogen
#include <tools/fract.hxx>
#endif
namespace binfilter {

/*************************************************************************/
/* FractionItem                                                          */
/*************************************************************************/

class SdrFractionItem: public SfxPoolItem {
	Fraction nValue;
public:
	TYPEINFO();
	SdrFractionItem(USHORT nId=0): SfxPoolItem(nId) {}
	SdrFractionItem(USHORT nId, const Fraction& rVal): SfxPoolItem(nId), nValue(rVal) {}
	SdrFractionItem(USHORT nId, SvStream& rIn);
	virtual int              operator==(const SfxPoolItem&) const;
	virtual SvStream&        Store(SvStream&, USHORT nItemVers) const;
	virtual SfxPoolItem*     Clone(SfxItemPool *pPool=NULL) const;
			const Fraction&  GetValue() const { return nValue; }
			void             SetValue(const Fraction& rVal) { nValue = rVal; }
#ifdef SDR_ISPOOLABLE
	virtual int IsPoolable() const;
#endif
};

}//end of namespace binfilter
#endif
