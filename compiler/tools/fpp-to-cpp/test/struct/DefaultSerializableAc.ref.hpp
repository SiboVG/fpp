// ======================================================================
// \title  DefaultSerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Default struct
// ======================================================================

#ifndef DefaultSerializableAc_HPP
#define DefaultSerializableAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

class Default :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // StringSize40 class
    // ----------------------------------------------------------------------

    class StringSize40 :
      public Fw::StringBase
    {
      public:

        enum {
          STRING_SIZE = 40,
          SERIALIZED_SIZE = STATIC_SERIALIZED_SIZE(STRING_SIZE)
        };

        StringSize40() : StringBase() { *this = ""; }

        explicit StringSize40(const StringSize40& src) : StringBase() { *this = src; }

        explicit StringSize40(const StringBase& src) : StringBase() { *this = src; }

         StringSize40(const char* src) : StringBase() { *this = src; }

        ~StringSize40() {}

        StringSize40& operator=(const StringSize40& src) {
          (void)StringBase::operator=(src);
          return *this;
        }

        StringSize40& operator=(const StringBase& src) {
          (void)StringBase::operator=(src);
          return *this;
        }

        StringSize40& operator=(const char* src) {
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

    //! The type of mU32
    using Type_of_mU32 = U32;

    //! The type of mS1
    using Type_of_mS1 = StringSize40;

    //! The type of mF64
    using Type_of_mF64 = F64;

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        sizeof(U32) +
        StringSize40::SERIALIZED_SIZE +
        sizeof(F64)
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    Default();

    //! Member constructor
    Default(
        U32 mU32,
        const Fw::StringBase& mS1,
        F64 mF64
    );

    //! Copy constructor
    Default(
        const Default& obj //!< The source object
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Copy assignment operator
    Default& operator=(
        const Default& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const Default& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const Default& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Default& obj //!< The object
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

#if FW_SERIALIZABLE_TO_STRING

    //! Convert struct to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    //! Get member mU32
    U32 getmU32() const
    {
      return this->m_mU32;
    }

    //! Get member mS1
    Type_of_mS1& getmS1()
    {
      return this->m_mS1;
    }

    //! Get member mS1 (const)
    const Type_of_mS1& getmS1() const
    {
      return this->m_mS1;
    }

    //! Get member mF64
    F64 getmF64() const
    {
      return this->m_mF64;
    }

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(
        U32 mU32,
        const Fw::StringBase& mS1,
        F64 mF64
    );

    //! Set member mU32
    void setmU32(U32 mU32);

    //! Set member mS1
    void setmS1(const Fw::StringBase& mS1);

    //! Set member mF64
    void setmF64(F64 mF64);

  protected:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    U32 m_mU32;
    StringSize40 m_mS1;
    F64 m_mF64;

};

#endif
