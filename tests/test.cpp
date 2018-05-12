/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:51:15 by asenat            #+#    #+#             */
/*   Updated: 2018/05/12 17:15:22 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cppunit/TestAssert.h>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>


class SimpleTest : public CppUnit::TestCase
{
	public:
		SimpleTest() : CppUnit::TestCase("SimpleTest") {}

		void runTest() {
			CPPUNIT_ASSERT( 1 == 1 );
			CPPUNIT_ASSERT( !(1 == 2) );
		}
};

int main() {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(new SimpleTest());
	runner.run();
	return 0;
}
