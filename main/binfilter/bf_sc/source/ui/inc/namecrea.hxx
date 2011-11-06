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



#ifndef SC_NAMECREA_HXX
#define SC_NAMECREA_HXX

#ifndef _SV_DIALOG_HXX //autogen
#include <vcl/dialog.hxx>
#endif

#ifndef _SV_BUTTON_HXX //autogen
#include <vcl/button.hxx>
#endif

#ifndef _SV_FIXED_HXX //autogen
#include <vcl/fixed.hxx>
#endif
namespace binfilter {


#define NAME_TOP		1
#define NAME_LEFT		2
#define NAME_BOTTOM		4
#define NAME_RIGHT		8

class ScNameCreateDlg : public ModalDialog
{
protected:
    FixedLine       aFixedLine;
	CheckBox		aTopBox;
	CheckBox		aLeftBox;
	CheckBox		aBottomBox;
	CheckBox		aRightBox;
	OKButton		aOKButton;
	CancelButton	aCancelButton;
	HelpButton		aHelpButton;
public:
	ScNameCreateDlg( Window * pParent, USHORT nFlags );

	USHORT			GetFlags() const;
};


} //namespace binfilter
#endif //SC_NAMECREA_HXX
