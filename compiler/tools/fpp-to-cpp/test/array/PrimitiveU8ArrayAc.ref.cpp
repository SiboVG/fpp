// ======================================================================
// \title  PrimitiveU8ArrayAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for PrimitiveU8 array
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "PrimitiveU8ArrayAc.hpp"

namespace M {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  PrimitiveU8 ::
    PrimitiveU8() :
      Serializable()
  {
    // Construct using element-wise constructor
    *this = PrimitiveU8(
      0,
      0,
      0
    );
  }

  PrimitiveU8 ::
    PrimitiveU8(const ElementType (&a)[SIZE]) :
      Serializable()
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = a[index];
    }
  }

  PrimitiveU8 ::
    PrimitiveU8(const ElementType& e) :
      Serializable()
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = e;
    }
  }

  PrimitiveU8 ::
    PrimitiveU8(
        const ElementType& e1,
        const ElementType& e2,
        const ElementType& e3
    ) :
      Serializable()
  {
    this->elements[0] = e1;
    this->elements[1] = e2;
    this->elements[2] = e3;
  }

  PrimitiveU8 ::
    PrimitiveU8(const PrimitiveU8& obj) :
      Serializable()
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = obj.elements[index];
    }
  }

  // ----------------------------------------------------------------------
  // Operators
  // ----------------------------------------------------------------------

  PrimitiveU8::ElementType& PrimitiveU8 ::
    operator[](const U32 i)
  {
    FW_ASSERT(i < SIZE, static_cast<FwAssertArgType>(i), static_cast<FwAssertArgType>(SIZE));
    return this->elements[i];
  }

  const PrimitiveU8::ElementType& PrimitiveU8 ::
    operator[](const U32 i) const
  {
    FW_ASSERT(i < SIZE, static_cast<FwAssertArgType>(i), static_cast<FwAssertArgType>(SIZE));
    return this->elements[i];
  }

  PrimitiveU8& PrimitiveU8 ::
    operator=(const PrimitiveU8& obj)
  {
    if (this == &obj) {
      return *this;
    }

    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = obj.elements[index];
    }
    return *this;
  }

  PrimitiveU8& PrimitiveU8 ::
    operator=(const ElementType (&a)[SIZE])
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = a[index];
    }
    return *this;
  }

  PrimitiveU8& PrimitiveU8 ::
    operator=(const ElementType& e)
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = e;
    }
    return *this;
  }

  bool PrimitiveU8 ::
    operator==(const PrimitiveU8& obj) const
  {
    for (U32 index = 0; index < SIZE; index++) {
      if (!((*this)[index] == obj[index])) {
        return false;
      }
    }
    return true;
  }

  bool PrimitiveU8 ::
    operator!=(const PrimitiveU8& obj) const
  {
    return !(*this == obj);
  }

#ifdef BUILD_UT

  std::ostream& operator<<(std::ostream& os, const PrimitiveU8& obj) {
    Fw::String s;
    obj.toString(s);
    os << s;
    return os;
  }

#endif

  // ----------------------------------------------------------------------
  // Public member functions
  // ----------------------------------------------------------------------

  Fw::SerializeStatus PrimitiveU8 ::
    serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
    for (U32 index = 0; index < SIZE; index++) {
      status = buffer.serialize((*this)[index]);
      if (status != Fw::FW_SERIALIZE_OK) {
        return status;
      }
    }
    return status;
  }

  Fw::SerializeStatus PrimitiveU8 ::
    deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
    for (U32 index = 0; index < SIZE; index++) {
      status = buffer.deserialize((*this)[index]);
      if (status != Fw::FW_SERIALIZE_OK) {
        return status;
      }
    }
    return status;
  }

#if FW_ARRAY_TO_STRING

  void PrimitiveU8 ::
    toString(Fw::StringBase& sb) const
  {
    static const char *formatString = "[ "
      "%" PRIu8 " "
      "%" PRIu8 " "
      "%" PRIu8 " ]";

    sb.format(
      formatString,
      this->elements[0],
      this->elements[1],
      this->elements[2]
    );
  }

#endif

}
