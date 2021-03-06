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



// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_chart2.hxx"
#include "MeanValueRegressionCurveCalculator.hxx"
#include "macros.hxx"

#include <rtl/math.hxx>
#include <rtl/ustrbuf.hxx>

using namespace ::com::sun::star;

using ::rtl::OUString;
using ::rtl::OUStringBuffer;

namespace chart
{

MeanValueRegressionCurveCalculator::MeanValueRegressionCurveCalculator() :
        m_fMeanValue( 0.0 )
{
    ::rtl::math::setNan( & m_fMeanValue );
}

MeanValueRegressionCurveCalculator::~MeanValueRegressionCurveCalculator()
{}

// ____ XRegressionCurveCalculator ____
void SAL_CALL MeanValueRegressionCurveCalculator::recalculateRegression(
    const uno::Sequence< double >& /*aXValues*/,
    const uno::Sequence< double >& aYValues )
    throw (uno::RuntimeException)
{
    const sal_Int32 nDataLength = aYValues.getLength();
    sal_Int32 nMax = nDataLength;
    double fSumY = 0.0;
    const double * pY = aYValues.getConstArray();

    for( sal_Int32 i = 0; i < nDataLength; ++i )
    {
        if( ::rtl::math::isNan( pY[i] ) ||
            ::rtl::math::isInf( pY[i] ))
            --nMax;
        else
            fSumY += pY[i];
    }

    m_fCorrelationCoeffitient = 0.0;

    if( nMax == 0 )
    {
        ::rtl::math::setNan( & m_fMeanValue );
    }
    else
    {
        m_fMeanValue = fSumY / static_cast< double >( nMax );

        // correlation coefficient: standard deviation
        if( nMax > 1 )
        {
            double fErrorSum = 0.0;
            for( sal_Int32 i = 0; i < nDataLength; ++i )
            {
                if( !::rtl::math::isNan( pY[i] ) &&
                    !::rtl::math::isInf( pY[i] ))
                {
                    double v = m_fMeanValue - pY[i];
                    fErrorSum += (v*v);
                }
            }
            OSL_ASSERT( fErrorSum >= 0.0 );
            m_fCorrelationCoeffitient = sqrt( fErrorSum / (nMax - 1 ));
        }
    }
}

double SAL_CALL MeanValueRegressionCurveCalculator::getCurveValue( double /*x*/ )
    throw (lang::IllegalArgumentException,
           uno::RuntimeException)
{
    return m_fMeanValue;
}


uno::Sequence< geometry::RealPoint2D > SAL_CALL MeanValueRegressionCurveCalculator::getCurveValues(
    double min, double max, ::sal_Int32 nPointCount,
    const uno::Reference< chart2::XScaling >& xScalingX,
    const uno::Reference< chart2::XScaling >& xScalingY,
    ::sal_Bool bMaySkipPointsInCalculation )
    throw (lang::IllegalArgumentException,
           uno::RuntimeException)
{
    if( bMaySkipPointsInCalculation )
    {
        // optimize result
        uno::Sequence< geometry::RealPoint2D > aResult( 2 );
        aResult[0].X = min;
        aResult[0].Y = m_fMeanValue;
        aResult[1].X = max;
        aResult[1].Y = m_fMeanValue;

        return aResult;
    }
    return RegressionCurveCalculator::getCurveValues( min, max, nPointCount, xScalingX, xScalingY, bMaySkipPointsInCalculation );
}

OUString MeanValueRegressionCurveCalculator::ImplGetRepresentation(
    const uno::Reference< util::XNumberFormatter >& xNumFormatter,
    ::sal_Int32 nNumberFormatKey ) const
{
    OUStringBuffer aBuf( C2U( "f(x) = " ));

    aBuf.append( getFormattedString( xNumFormatter, nNumberFormatKey, m_fMeanValue ));

    return aBuf.makeStringAndClear();
}

} //  namespace chart
