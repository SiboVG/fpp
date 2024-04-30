// ======================================================================
// \title  String1ArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for String1 array
// ======================================================================

#ifndef String1ArrayAc_HPP
#define String1ArrayAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

//! An array of strings
class String1 :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // StringSize80 class
    // ----------------------------------------------------------------------

    class StringSize80 :
      public Fw::StringBase
    {
      public:

        enum {
          STRING_SIZE = 80,
          SERIALIZED_SIZE = STATIC_SERIALIZED_SIZE(STRING_SIZE)
        };

        StringSize80() : StringBase() { *this = ""; }

        explicit StringSize80(const StringSize80& src) : StringBase() { *this = src; }

        explicit StringSize80(const StringBase& src) : StringBase() { *this = src; }

         StringSize80(const char* src) : StringBase() { *this = src; }

        ~StringSize80() {}

        StringSize80& operator=(const StringSize80& src) {
          (void)StringBase::operator=(src);
          return *this;
        }

        StringSize80& operator=(const StringBase& src) {
          (void)StringBase::operator=(src);
          return *this;
        }

        StringSize80& operator=(const char* src) {
          (void)StringBase::operator=(src);
          return *this;
        }

        const char* toChar() const { return this->m_buf; }

        StringBase::SizeType getCapacity() const { return sizeof this->m_buf; }

      private:

        char m_buf[BUFFER_SIZE(STRING_SIZE)];

    };

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The element type
    typedef StringSize80 ElementType;

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the array
      SIZE = 3,
      //! The size of the serial representation
      SERIALIZED_SIZE = SIZE * StringSize80::SERIALIZED_SIZE,
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    String1();

    //! Constructor (user-provided value)
    String1(
        const ElementType (&a)[SIZE] //!< The array
    );

    //! Constructor (single element)
    String1(
        const Fw::StringBase& e //!< The element
    );

    //! Constructor (multiple elements)
    String1(
        const Fw::StringBase& e1, //!< Element 1
        const Fw::StringBase& e2, //!< Element 2
        const Fw::StringBase& e3 //!< Element 3
    );

    //! Copy Constructor
    String1(
        const String1& obj //!< The source object
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Subscript operator
    ElementType& operator[](
        const U32 i //!< The subscript index
    );

    //! Const subscript operator
    const ElementType& operator[](
        const U32 i //!< The subscript index
    ) const;

    //! Copy assignment operator (object)
    String1& operator=(
        const String1& obj //!< The source object
    );

    //! Copy assignment operator (raw array)
    String1& operator=(
        const ElementType (&a)[SIZE] //!< The source array
    );

    //! Copy assignment operator (single element)
    String1& operator=(
        const ElementType& e //!< The element
    );

    //! Equality operator
    bool operator==(
        const String1& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const String1& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const String1& obj //!< The object
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Member functions
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    );

#if FW_ARRAY_TO_STRING

    //! Convert array to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The array elements
    ElementType elements[SIZE];

};

#endif
