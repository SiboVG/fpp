// ======================================================================
// \title  EnumSerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Enum struct
// ======================================================================

#include "cstdio"
#include "cstring"

#include "EnumSerializableAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Enum ::
  Enum() :
    Serializable(),
    e(M::E::X)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->eArr[i] = M::E::X;
  }
}

Enum ::
  Enum(
      M::E::T e,
      const Type_of_eArr& eArr
  ) :
    Serializable(),
    e(e)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->eArr[i] = eArr[i];
  }
}

Enum ::
  Enum(const Enum& obj) :
    Serializable(),
    e(obj.e)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->eArr[i] = obj.eArr[i];
  }
}

Enum ::
  Enum(
      M::E::T e,
      M::E::T eArr
  ) :
    Serializable(),
    e(e)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->eArr[i] = eArr;
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Enum& Enum ::
  operator=(const Enum& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.e, obj.eArr);
  return *this;
}

bool Enum ::
  operator==(const Enum& obj) const
{
  // Compare non-array members
  if (!(this->e == obj.e)) {
    return false;
  }

  // Compare array members
  if (!(this->eArr == obj.eArr)) {
    for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
      if (!(this->eArr[i] == obj.eArr[i])) {
        return false;
      }
    }
  }

  return true;
}

bool Enum ::
  operator!=(const Enum& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Enum& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Enum ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->e);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    status = buffer.serialize(this->eArr[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

Fw::SerializeStatus Enum ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->e);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    status = buffer.deserialize(this->eArr[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void Enum ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "e = %s, "
    "eArr = [ %s, "
    "%s, "
    "%s ]"
    " )";

  // Declare strings to hold any serializable toString() arguments
  Fw::String eStr;
  Fw::String eArrStr[3];

  // Call toString for arrays and serializable types
  this->e.toString(eStr);
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->eArr[i].toString(eArrStr[i]);
  }

  char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,
    formatString,
    eStr.toChar(),
    eArrStr[0].toChar(),
    eArrStr[1].toChar(),
    eArrStr[2].toChar()
  );

  outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void Enum ::
  set(
      M::E::T e,
      const Type_of_eArr& eArr
  )
{
  this->e = e;

  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->eArr[i] = eArr[i];
  }
}

void Enum ::
  sete(M::E::T e)
{
  this->e = e;
}

void Enum ::
  seteArr(const Type_of_eArr& eArr)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->eArr[i] = eArr[i];
  }
}
