// ======================================================================
// \title  PassiveGuardedProductsGTestBase.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PassiveGuardedProducts component Google Test harness base class
// ======================================================================

#ifndef PassiveGuardedProductsGTestBase_HPP
#define PassiveGuardedProductsGTestBase_HPP

#include "gtest/gtest.h"
#include "test-base/PassiveGuardedProductsTesterBase.hpp"

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_noArgsOut_SIZE(size) \
  this->assert_from_noArgsOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_noArgsOut(index) \
  { \
    ASSERT_GT(this->fromPortHistory_noArgsOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of noArgsOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_noArgsOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_noArgsOut& _e = \
        this->fromPortHistory_noArgsOut->at(index); \
  }

#define ASSERT_from_noArgsReturnOut_SIZE(size) \
  this->assert_from_noArgsReturnOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_noArgsReturnOut(index) \
  { \
    ASSERT_GT(this->fromPortHistory_noArgsReturnOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of noArgsReturnOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_noArgsReturnOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_noArgsReturnOut& _e = \
        this->fromPortHistory_noArgsReturnOut->at(index); \
  }

#define ASSERT_from_noArgsStringReturnOut_SIZE(size) \
  this->assert_from_noArgsStringReturnOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_noArgsStringReturnOut(index) \
  { \
    ASSERT_GT(this->fromPortHistory_noArgsStringReturnOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of noArgsStringReturnOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_noArgsStringReturnOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_noArgsStringReturnOut& _e = \
        this->fromPortHistory_noArgsStringReturnOut->at(index); \
  }

#define ASSERT_from_typedAliasOut_SIZE(size) \
  this->assert_from_typedAliasOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_typedAliasOut(index, _u32, _f32, _b, _str2, _e, _a, _s) \
  { \
    ASSERT_GT(this->fromPortHistory_typedAliasOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of typedAliasOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_typedAliasOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_typedAliasOut& _e = \
        this->fromPortHistory_typedAliasOut->at(index); \
    ASSERT_EQ(_u32, _e.u32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument u32 at index " \
      << index \
      << " in history of typedAliasOut\n" \
      << "  Expected: " << _u32 << "\n" \
      << "  Actual:   " << _e.u32 << "\n"; \
    ASSERT_EQ(_f32, _e.f32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument f32 at index " \
      << index \
      << " in history of typedAliasOut\n" \
      << "  Expected: " << _f32 << "\n" \
      << "  Actual:   " << _e.f32 << "\n"; \
    ASSERT_EQ(_b, _e.b) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument b at index " \
      << index \
      << " in history of typedAliasOut\n" \
      << "  Expected: " << _b << "\n" \
      << "  Actual:   " << _e.b << "\n"; \
    ASSERT_EQ(_str2, _e.str2) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument str2 at index " \
      << index \
      << " in history of typedAliasOut\n" \
      << "  Expected: " << _str2 << "\n" \
      << "  Actual:   " << _e.str2 << "\n"; \
    ASSERT_EQ(_e, _e.e) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument e at index " \
      << index \
      << " in history of typedAliasOut\n" \
      << "  Expected: " << _e << "\n" \
      << "  Actual:   " << _e.e << "\n"; \
    ASSERT_EQ(_a, _e.a) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument a at index " \
      << index \
      << " in history of typedAliasOut\n" \
      << "  Expected: " << _a << "\n" \
      << "  Actual:   " << _e.a << "\n"; \
    ASSERT_EQ(_s, _e.s) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument s at index " \
      << index \
      << " in history of typedAliasOut\n" \
      << "  Expected: " << _s << "\n" \
      << "  Actual:   " << _e.s << "\n"; \
  }

#define ASSERT_from_typedAliasReturnOut_SIZE(size) \
  this->assert_from_typedAliasReturnOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_typedAliasReturnOut(index, _u32, _f32, _b, _str2, _e, _a, _s) \
  { \
    ASSERT_GT(this->fromPortHistory_typedAliasReturnOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of typedAliasReturnOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_typedAliasReturnOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_typedAliasReturnOut& _e = \
        this->fromPortHistory_typedAliasReturnOut->at(index); \
    ASSERT_EQ(_u32, _e.u32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument u32 at index " \
      << index \
      << " in history of typedAliasReturnOut\n" \
      << "  Expected: " << _u32 << "\n" \
      << "  Actual:   " << _e.u32 << "\n"; \
    ASSERT_EQ(_f32, _e.f32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument f32 at index " \
      << index \
      << " in history of typedAliasReturnOut\n" \
      << "  Expected: " << _f32 << "\n" \
      << "  Actual:   " << _e.f32 << "\n"; \
    ASSERT_EQ(_b, _e.b) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument b at index " \
      << index \
      << " in history of typedAliasReturnOut\n" \
      << "  Expected: " << _b << "\n" \
      << "  Actual:   " << _e.b << "\n"; \
    ASSERT_EQ(_str2, _e.str2) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument str2 at index " \
      << index \
      << " in history of typedAliasReturnOut\n" \
      << "  Expected: " << _str2 << "\n" \
      << "  Actual:   " << _e.str2 << "\n"; \
    ASSERT_EQ(_e, _e.e) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument e at index " \
      << index \
      << " in history of typedAliasReturnOut\n" \
      << "  Expected: " << _e << "\n" \
      << "  Actual:   " << _e.e << "\n"; \
    ASSERT_EQ(_a, _e.a) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument a at index " \
      << index \
      << " in history of typedAliasReturnOut\n" \
      << "  Expected: " << _a << "\n" \
      << "  Actual:   " << _e.a << "\n"; \
    ASSERT_EQ(_s, _e.s) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument s at index " \
      << index \
      << " in history of typedAliasReturnOut\n" \
      << "  Expected: " << _s << "\n" \
      << "  Actual:   " << _e.s << "\n"; \
  }

#define ASSERT_from_typedAliasReturnStringOut_SIZE(size) \
  this->assert_from_typedAliasReturnStringOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_typedAliasReturnStringOut(index, _u32, _f32, _b, _str2, _e, _a, _s) \
  { \
    ASSERT_GT(this->fromPortHistory_typedAliasReturnStringOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of typedAliasReturnStringOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_typedAliasReturnStringOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_typedAliasReturnStringOut& _e = \
        this->fromPortHistory_typedAliasReturnStringOut->at(index); \
    ASSERT_EQ(_u32, _e.u32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument u32 at index " \
      << index \
      << " in history of typedAliasReturnStringOut\n" \
      << "  Expected: " << _u32 << "\n" \
      << "  Actual:   " << _e.u32 << "\n"; \
    ASSERT_EQ(_f32, _e.f32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument f32 at index " \
      << index \
      << " in history of typedAliasReturnStringOut\n" \
      << "  Expected: " << _f32 << "\n" \
      << "  Actual:   " << _e.f32 << "\n"; \
    ASSERT_EQ(_b, _e.b) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument b at index " \
      << index \
      << " in history of typedAliasReturnStringOut\n" \
      << "  Expected: " << _b << "\n" \
      << "  Actual:   " << _e.b << "\n"; \
    ASSERT_EQ(_str2, _e.str2) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument str2 at index " \
      << index \
      << " in history of typedAliasReturnStringOut\n" \
      << "  Expected: " << _str2 << "\n" \
      << "  Actual:   " << _e.str2 << "\n"; \
    ASSERT_EQ(_e, _e.e) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument e at index " \
      << index \
      << " in history of typedAliasReturnStringOut\n" \
      << "  Expected: " << _e << "\n" \
      << "  Actual:   " << _e.e << "\n"; \
    ASSERT_EQ(_a, _e.a) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument a at index " \
      << index \
      << " in history of typedAliasReturnStringOut\n" \
      << "  Expected: " << _a << "\n" \
      << "  Actual:   " << _e.a << "\n"; \
    ASSERT_EQ(_s, _e.s) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument s at index " \
      << index \
      << " in history of typedAliasReturnStringOut\n" \
      << "  Expected: " << _s << "\n" \
      << "  Actual:   " << _e.s << "\n"; \
  }

#define ASSERT_from_typedOut_SIZE(size) \
  this->assert_from_typedOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_typedOut(index, _u32, _f32, _b, _str1, _e, _a, _s) \
  { \
    ASSERT_GT(this->fromPortHistory_typedOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of typedOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_typedOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_typedOut& _e = \
        this->fromPortHistory_typedOut->at(index); \
    ASSERT_EQ(_u32, _e.u32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument u32 at index " \
      << index \
      << " in history of typedOut\n" \
      << "  Expected: " << _u32 << "\n" \
      << "  Actual:   " << _e.u32 << "\n"; \
    ASSERT_EQ(_f32, _e.f32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument f32 at index " \
      << index \
      << " in history of typedOut\n" \
      << "  Expected: " << _f32 << "\n" \
      << "  Actual:   " << _e.f32 << "\n"; \
    ASSERT_EQ(_b, _e.b) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument b at index " \
      << index \
      << " in history of typedOut\n" \
      << "  Expected: " << _b << "\n" \
      << "  Actual:   " << _e.b << "\n"; \
    ASSERT_EQ(_str1, _e.str1) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument str1 at index " \
      << index \
      << " in history of typedOut\n" \
      << "  Expected: " << _str1 << "\n" \
      << "  Actual:   " << _e.str1 << "\n"; \
    ASSERT_EQ(_e, _e.e) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument e at index " \
      << index \
      << " in history of typedOut\n" \
      << "  Expected: " << _e << "\n" \
      << "  Actual:   " << _e.e << "\n"; \
    ASSERT_EQ(_a, _e.a) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument a at index " \
      << index \
      << " in history of typedOut\n" \
      << "  Expected: " << _a << "\n" \
      << "  Actual:   " << _e.a << "\n"; \
    ASSERT_EQ(_s, _e.s) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument s at index " \
      << index \
      << " in history of typedOut\n" \
      << "  Expected: " << _s << "\n" \
      << "  Actual:   " << _e.s << "\n"; \
  }

#define ASSERT_from_typedReturnOut_SIZE(size) \
  this->assert_from_typedReturnOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_typedReturnOut(index, _u32, _f32, _b, _str2, _e, _a, _s) \
  { \
    ASSERT_GT(this->fromPortHistory_typedReturnOut->size(), static_cast<U32>(index)) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Index into history of typedReturnOut\n" \
      << "  Expected: Less than size of history (" \
      << this->fromPortHistory_typedReturnOut->size() << ")\n" \
      << "  Actual:   " << index << "\n"; \
      const FromPortEntry_typedReturnOut& _e = \
        this->fromPortHistory_typedReturnOut->at(index); \
    ASSERT_EQ(_u32, _e.u32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument u32 at index " \
      << index \
      << " in history of typedReturnOut\n" \
      << "  Expected: " << _u32 << "\n" \
      << "  Actual:   " << _e.u32 << "\n"; \
    ASSERT_EQ(_f32, _e.f32) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument f32 at index " \
      << index \
      << " in history of typedReturnOut\n" \
      << "  Expected: " << _f32 << "\n" \
      << "  Actual:   " << _e.f32 << "\n"; \
    ASSERT_EQ(_b, _e.b) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument b at index " \
      << index \
      << " in history of typedReturnOut\n" \
      << "  Expected: " << _b << "\n" \
      << "  Actual:   " << _e.b << "\n"; \
    ASSERT_EQ(_str2, _e.str2) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument str2 at index " \
      << index \
      << " in history of typedReturnOut\n" \
      << "  Expected: " << _str2 << "\n" \
      << "  Actual:   " << _e.str2 << "\n"; \
    ASSERT_EQ(_e, _e.e) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument e at index " \
      << index \
      << " in history of typedReturnOut\n" \
      << "  Expected: " << _e << "\n" \
      << "  Actual:   " << _e.e << "\n"; \
    ASSERT_EQ(_a, _e.a) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument a at index " \
      << index \
      << " in history of typedReturnOut\n" \
      << "  Expected: " << _a << "\n" \
      << "  Actual:   " << _e.a << "\n"; \
    ASSERT_EQ(_s, _e.s) \
      << "\n" \
      << __FILE__ << ":" << __LINE__ << "\n" \
      << "  Value:    Value of argument s at index " \
      << index \
      << " in history of typedReturnOut\n" \
      << "  Expected: " << _s << "\n" \
      << "  Actual:   " << _e.s << "\n"; \
  }

// ----------------------------------------------------------------------
// Macros for product request assertions
// ----------------------------------------------------------------------

#define ASSERT_PRODUCT_REQUEST_SIZE(size) \
  this->assertProductRequest_size(__FILE__, __LINE__, size)

#define ASSERT_PRODUCT_REQUEST(index, id, size) \
  this->assertProductRequest(__FILE__, __LINE__, index, id, size)

// ----------------------------------------------------------------------
// Macros for product send assertions
// ----------------------------------------------------------------------

#define ASSERT_PRODUCT_SEND_SIZE(size) \
  this->assertProductSend_size(__FILE__, __LINE__, size)

#define ASSERT_PRODUCT_SEND(index, id, priority, timeTag, procTypes, userData, dpState, dataSize, buffer) \
    assertProductSend(__FILE__, __LINE__, index, id, priority, timeTag, procTypes, userData, dpState, dataSize, buffer)

//! \class PassiveGuardedProductsGTestBase
//! \brief Auto-generated base for PassiveGuardedProducts component Google Test harness
class PassiveGuardedProductsGTestBase :
  public PassiveGuardedProductsTesterBase
{

  protected:

    // ----------------------------------------------------------------------
    // Construction and destruction
    // ----------------------------------------------------------------------

    //! Construct object PassiveGuardedProductsGTestBase
    PassiveGuardedProductsGTestBase(
        const char* const compName, //!< The component name
        const U32 maxHistorySize //!< The maximum size of each history
    );

    //! Destroy object PassiveGuardedProductsGTestBase
    ~PassiveGuardedProductsGTestBase();

  protected:

    // ----------------------------------------------------------------------
    // From ports
    // ----------------------------------------------------------------------

    //! From ports
    void assertFromPortHistory_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: noArgsOut
    void assert_from_noArgsOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: noArgsReturnOut
    void assert_from_noArgsReturnOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: noArgsStringReturnOut
    void assert_from_noArgsStringReturnOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: typedAliasOut
    void assert_from_typedAliasOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: typedAliasReturnOut
    void assert_from_typedAliasReturnOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: typedAliasReturnStringOut
    void assert_from_typedAliasReturnStringOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: typedOut
    void assert_from_typedOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! From port: typedReturnOut
    void assert_from_typedReturnOut_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

  protected:

    // ----------------------------------------------------------------------
    // Data Product Request
    // ----------------------------------------------------------------------

    //! Assert size of product request history
    void assertProductRequest_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! Assert the product request history at index
    void assertProductRequest(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 __index, //!< The index
        FwDpIdType id, //!< The container ID
        FwSizeType size //!< The size of the requested buffer
    ) const;

  protected:

    // ----------------------------------------------------------------------
    // Data Product Send
    // ----------------------------------------------------------------------

    //! Assert size of product send history
    void assertProductSend_size(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 size //!< The asserted size
    ) const;

    //! Assert the product send history at index
    //!
    //! This function sets the output buffer, deserializes and checks the
    //! data product header, and sets the deserialization pointer to the start
    //! of the data payload. User-written code can then check the data payload.
    void assertProductSend(
        const char* const __callSiteFileName, //!< The name of the file containing the call site
        const U32 __callSiteLineNumber, //!< The line number of the call site
        const U32 __index, //!< The index
        FwDpIdType id, //!< The expected container ID (input)
        FwDpPriorityType priority, //!< The expected priority (input)
        const Fw::Time& timeTag, //!< The expected time tag (input)
        Fw::DpCfg::ProcType::SerialType procTypes, //!< The expected processing types (input)
        const Fw::DpContainer::Header::UserData& userData, //!< The expected user data (input)
        Fw::DpState dpState, //!< The expected data product state (input)
        FwSizeType dataSize, //!< The expected data size (input)
        Fw::Buffer& historyBuffer //!< The buffer from the history (output)
    ) const;

};

#endif
