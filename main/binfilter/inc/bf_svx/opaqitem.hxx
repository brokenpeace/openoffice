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


#ifndef _SVX_OPAQITEM_HXX
#define _SVX_OPAQITEM_HXX

#include <bf_svtools/bf_solar.h>

// include ---------------------------------------------------------------

#ifndef _SFXENUMITEM_HXX //autogen
#include <bf_svtools/eitem.hxx>
#endif

namespace rtl
{
	class OUString;
}
namespace binfilter {
class SvXMLUnitConverter;
// class SvxOpaqueItem ---------------------------------------------------

/*
[Beschreibung]
Dieses Item beschreibt eine logische Variable "Undurchsichtig ja oder nein".
*/

class SvxOpaqueItem : public SfxBoolItem
{
public:
	TYPEINFO();

	SvxOpaqueItem( const USHORT nId = ITEMID_OPAQUE, const BOOL bOpa = TRUE );
	inline SvxOpaqueItem &operator=( const SvxOpaqueItem &rCpy );

	// "pure virtual Methoden" vom SfxPoolItem
	virtual SfxPoolItem*    Clone( SfxItemPool *pPool = 0 ) const;
	virtual SfxPoolItem*    Create(SvStream &, USHORT) const;
	virtual SvStream&		Store(SvStream &, USHORT nItemVersion ) const;

};

inline SvxOpaqueItem::SvxOpaqueItem( const USHORT nId, const BOOL bOpa )
	: SfxBoolItem( nId, bOpa )
{}

inline SvxOpaqueItem &SvxOpaqueItem::operator=( const SvxOpaqueItem &rCpy )
{
	SetValue( rCpy.GetValue() );
	return *this;
}

}//end of namespace binfilter
#endif

