///////////////////////////////////////////////////////////////////////////////
// Unit Test for Loki
//
// Copyright Terje Sletteb� and Pavel Vozenilek 2002.
//
// Permission to use, copy, modify, and distribute this software for any
// purpose is hereby granted without fee, provided that this copyright and
// permissions notice appear in all copies and derivatives.
//
// This software is provided "as is" without express or implied warranty.
//
///////////////////////////////////////////////////////////////////////////////

// $Header$

#ifdef __INTEL_COMPILER
# pragma warning(disable: 111 193 304 383 444 488 981 1418)
#elif defined(_MSC_VER) && !defined(__MWERKS__)
# pragma warning(disable: 4018 4097 4100 4213 4290 4512 4514 4700 4702 4710 4786 4800)
#endif

//#define LOKI_CLASS_LEVEL_THREADING
//#define LOKI_OBJECT_LEVEL_THREADING

// Some platforms might have difficulty with this
// Need to ifdef around those cases.
// TODO SGB


#include "UnitTest.h"

// static variable defintion, do not remove

Test::tests_type Test::tests;

// Merely comment out any of the following headers to
// prevent thier execution during the test.
//
// A pluggable-factory-like method is used to 
// auto-register the test, so all that is needed
// is the header inclusion to execute the correspond
// unit test.

#include "TypelistTest.h"
#include "SequenceTest.h"
#include "TypeManipTest.h"
#include "TypeTraitsTest.h"
#include "TypeTraitsTest2.h"
#include "SmallObjectTest.h"
#include "SingletonTest.h"
#include "SmartPtrTest.h"
#include "FactoryTest.h"
#include "FactoryParmTest.h"
#include "AbstractFactoryTest.h"
#include "AssocVectorTest.h"
#include "FunctorTest.h"
#include "DataGeneratorsTest.h"

/*
 * AP - All Pass
 * FC - Fails to Compile
 * ?  - Unknown/Not Tested/Not Recorded
 *
 *               TypelistTest    TypeManipTest  TypeTraitsTest  SmallObjectTest  SingletonTest
 * gcc   2.95.3  ?               ?              ?               ?                ?
 * gcc   3.2     AP              AP             AP              AP               P (Only SingleThreaded)
 * MSVC  6.0     P               AP             FC              FC               AP
 * MSVC  7.0     AP              Conversion     FC              AP               P (Only SingleThreaded) ?
 * Intel 5.0     AP              AP             AP              FC               FC
 * Intel 6.0     AP              AP             AP              FC               P (Only SingleThreaded)
 * Intel 7.0     AP              AP             AP              FC               P (Only SingleThreaded)
 * BCC   5.5     ?               ?              ?               ?                ?
 * BCC   5.6     ?               ?              ?               ?                ?
 * CW    6.0     ?               ?              ?               ?                ?
 *
 *               SmartPtrTest  FactoryTest  AbstractFactoryTest  AssocVectorTest  FunctorTest
 * gcc   2.95.3  ?             ?            ?                    ?                ?
 * gcc   3.2     AP            AP           AP                   AP               AP
 * MSVC  6.0     FC            AP           FC                   FC               FC
 * MSVC  7.0     FC            AP           AP                   FC               AP
 * Intel 5.0     FC            FC           FC                   FC               FC
 * Intel 6.0     FC            AP           AP                   FC               FC
 * Intel 7.0     FC            AP           AP                   FC               FC
 * BCC   5.5     ?             ?            ?                    ?                ?
 * CW    6.0     ?             ?            ?                    ?                ?
 *
 *               DataGeneratorsTest
 * gcc   2.95.3  ?
 * gcc   3.2     AP
 * MSVC  6.0     FC
 * MSVC  7.0     AP
 * Intel 5.0     FC
 * Intel 6.0     AP
 * Intel 7.0     AP
 * BCC   5.5     ?
 * BCC   5.6     ?
 * CW    6.0     ?                 

 */ 

int main()
{

int result = Test::run("Loki Unit Test");

#if defined(__BORLANDC__) || defined(__GNUC__) || defined(_MSC_VER)
  system("pause"); // Stop console window from closing if run from IDE.
#endif

return result;
}


// $Log$
// Revision 1.8  2005/10/06 17:50:14  syntheticpp
// adding template based list/sequence implementation, should replace LOKI_TYPELIST_, update some files
//
// Revision 1.7  2005/09/29 08:09:17  syntheticpp
// update msvc build process
//
// Revision 1.6  2005/09/26 07:33:05  syntheticpp
// move macros into LOKI_ namespace
//
// Revision 1.5  2005/09/24 15:49:40  syntheticpp
// is it really binary?
//
// Revision 1.4  2005/09/24 15:25:20  syntheticpp
// ove RegressionTest
//
// Revision 1.17  2005/09/15 17:51:48  syntheticpp
// add new TypeTraits test from Kalle Rutanen
//
// Revision 1.16  2005/08/10 18:13:13  syntheticpp
// change default to single threading
//
// Revision 1.15  2005/07/31 14:00:48  syntheticpp
// make object level threading possible
//
// Revision 1.14  2005/07/28 14:26:10  syntheticpp
// add cvs Header/Log
//
