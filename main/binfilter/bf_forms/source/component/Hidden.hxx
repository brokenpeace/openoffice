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



#ifndef _FORMS_HIDDEN_HXX_
#define _FORMS_HIDDEN_HXX_

#ifndef _FORMS_FORMCOMPONENT_HXX_
#include "FormComponent.hxx"
#endif
namespace binfilter {

//.........................................................................
namespace frm
{

//==================================================================
// OHiddenModel
//==================================================================
class OHiddenModel
		:public OControlModel
		,public ::comphelper::OAggregationArrayUsageHelper< OHiddenModel >
{
	::rtl::OUString		m_sHiddenValue;

public:
	DECLARE_DEFAULT_LEAF_XTOR( OHiddenModel );

	// OPropertySetHelper
	virtual void SAL_CALL getFastPropertyValue(::com::sun::star::uno::Any& rValue, sal_Int32 nHandle) const;
	virtual void SAL_CALL setFastPropertyValue_NoBroadcast( sal_Int32 nHandle, const ::com::sun::star::uno::Any& rValue )
				throw (::com::sun::star::uno::Exception);
	virtual sal_Bool SAL_CALL convertFastPropertyValue(
				::com::sun::star::uno::Any& _rConvertedValue, ::com::sun::star::uno::Any& _rOldValue, sal_Int32 _nHandle, const ::com::sun::star::uno::Any& _rValue )
				throw (::com::sun::star::lang::IllegalArgumentException);

	// XPropertySetRef
	virtual ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySetInfo> SAL_CALL getPropertySetInfo() throw(::com::sun::star::uno::RuntimeException);
	virtual cppu::IPropertyArrayHelper& SAL_CALL getInfoHelper();

	// XServiceInfo
	IMPLEMENTATION_NAME(OHiddenModel);
	virtual StringSequence SAL_CALL	getSupportedServiceNames() throw(::com::sun::star::uno::RuntimeException);

	// XPersistObject
    virtual ::rtl::OUString SAL_CALL	getServiceName() throw(::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL
		write(const ::com::sun::star::uno::Reference< ::com::sun::star::io::XObjectOutputStream>& _rxOutStream) throw(::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL
		read(const ::com::sun::star::uno::Reference< ::com::sun::star::io::XObjectInputStream>& _rxInStream) throw(::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);

// OAggregationArrayUsageHelper
	virtual void fillProperties(
		::com::sun::star::uno::Sequence< ::com::sun::star::beans::Property >& /* [out] */ _rProps,
		::com::sun::star::uno::Sequence< ::com::sun::star::beans::Property >& /* [out] */ _rAggregateProps
		) const;
	IMPLEMENT_INFO_SERVICE()

protected:
	DECLARE_XCLONEABLE( );
};

}
#endif // _FORMS_HIDDEN_HXX_

//.........................................................................
}//end of namespace binfilter
//.........................................................................

