// ======================================================================
// \title  PrimitiveStructSerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PrimitiveStruct struct
// ======================================================================

#ifndef PrimitiveStructSerializableAc_HPP
#define PrimitiveStructSerializableAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"
#include "PrimitiveSerializableAc.hpp"

class PrimitiveStruct :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        Primitive::SERIALIZED_SIZE
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    PrimitiveStruct();

    //! Member constructor
    PrimitiveStruct(const Primitive& s1);

    //! Copy constructor
    PrimitiveStruct(
        const PrimitiveStruct& obj //!< The source object
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Copy assignment operator
    PrimitiveStruct& operator=(
        const PrimitiveStruct& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const PrimitiveStruct& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const PrimitiveStruct& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const PrimitiveStruct& obj //!< The object
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

#if FW_SERIALIZABLE_TO_STRING || BUILD_UT

    //! Convert struct to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    //! Get member s1
    Primitive& gets1()
    {
      return this->s1;
    }

    //! Get member s1 (const)
    const Primitive& gets1() const
    {
      return this->s1;
    }

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(const Primitive& s1);

    //! Set member s1
    void sets1(const Primitive& s1);

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    Primitive s1;

};

#endif
