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


#ifndef _SWSTBCTL_HXX
#define _SWSTBCTL_HXX

#include <bf_svtools/bf_solar.h>

// include ---------------------------------------------------------------

#ifndef _SFXSTBITEM_HXX //autogen
#include <bf_sfx2/stbitem.hxx>
#endif
namespace binfilter {

// class  SwHyperlinkControl ------------------------------------------------

class  SwHyperlinkControl : public SfxStatusBarControl
{
public:
	virtual void	StateChanged( USHORT nSID, SfxItemState eState,
								  const SfxPoolItem* pState );

	SFX_DECL_STATUSBAR_CONTROL();

	 SwHyperlinkControl( USHORT nId, StatusBar& rStb, SfxBindings& rBind );

private:
	BOOL	bState;
	void 	DrawItemText_Impl();

};


} //namespace binfilter
#endif

