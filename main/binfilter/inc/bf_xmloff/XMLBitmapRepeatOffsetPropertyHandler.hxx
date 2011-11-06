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



#ifndef _XMLOFF_XMLBITMAPREPEATOFFSETPROPERTYHANDLER_HXX
#define _XMLOFF_XMLBITMAPREPEATOFFSETPROPERTYHANDLER_HXX

#ifndef _XMLOFF_PROPERTYHANDLERBASE_HXX
#include "xmlprhdl.hxx"
#endif
namespace binfilter {

struct SvXMLEnumMapEntry;

///////////////////////////////////////////////////////////////////////////
//
/** Abstract base-class for different XML-types. Derivations of this class
    knows how to compare, im/export a special XML-type
*/
class XMLBitmapRepeatOffsetPropertyHandler: public XMLPropertyHandler
{
	sal_Bool mbX;
	::rtl::OUString	msVertical;
	::rtl::OUString msHorizontal;
public:

	XMLBitmapRepeatOffsetPropertyHandler( sal_Bool bX );

	// Just needed for virtual destruction
	virtual ~XMLBitmapRepeatOffsetPropertyHandler();

	/// Imports the given value in cas of the given XML-data-type
	virtual sal_Bool importXML(
			const ::rtl::OUString& rStrImpValue,
			::com::sun::star::uno::Any& rValue,
			const SvXMLUnitConverter& rUnitConverter ) const;

	/// Exports the given value in cas of the given XML-data-type
	virtual sal_Bool exportXML(
			::rtl::OUString& rStrExpValue,
			const ::com::sun::star::uno::Any& rValue,
			const SvXMLUnitConverter& rUnitConverter ) const;
};

}//end of namespace binfilter
#endif		// _XMLOFF_XMLBITMAPREPEATOFFSETPROPERTYHANDLER_HXX
