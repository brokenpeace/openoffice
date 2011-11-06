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



#ifndef _SC_XMLCONSOLIDATIONCONTEXT_HXX
#define _SC_XMLCONSOLIDATIONCONTEXT_HXX

#ifndef SC_SCGLOB_HXX
#include "global.hxx"
#endif

#ifndef _XMLOFF_XMLIMP_HXX
#include <bf_xmloff/xmlimp.hxx>
#endif
namespace binfilter {

class ScXMLImport;


//___________________________________________________________________

class ScXMLConsolidationContext : public SvXMLImportContext
{
private:
	::rtl::OUString				sSourceList;
	::rtl::OUString				sUseLabel;
	ScAddress					aTargetAddr;
	ScSubTotalFunc				eFunction;
	sal_Bool					bLinkToSource : 1;
	sal_Bool					bTargetAddr : 1;

protected:
	const ScXMLImport&			GetScImport() const	{ return (const ScXMLImport&)GetImport(); }
	ScXMLImport&				GetScImport()		{ return (ScXMLImport&)GetImport(); }

public:
								ScXMLConsolidationContext(
									ScXMLImport& rImport,
									USHORT nPrfx,
									const ::rtl::OUString& rLName,
									const ::com::sun::star::uno::Reference< ::com::sun::star::xml::sax::XAttributeList >& xAttrList
									);
	virtual						~ScXMLConsolidationContext();

	virtual SvXMLImportContext*	CreateChildContext(
									USHORT nPrefix,
									const ::rtl::OUString& rLocalName,
									const ::com::sun::star::uno::Reference< ::com::sun::star::xml::sax::XAttributeList >& xAttrList
									);
	virtual void				EndElement();
};


} //namespace binfilter
#endif

