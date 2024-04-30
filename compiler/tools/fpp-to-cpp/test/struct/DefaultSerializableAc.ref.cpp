// ======================================================================
// \title  DefaultSerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Default struct
// ======================================================================

#include <cstdio>
#include <cstring>

#include "DefaultSerializableAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

// ----------------------------------------------------------------------
// StringSize40 class
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Default ::
  Default() :
    Serializable(),
    m_mU32(54),
    m_mS1(Fw::String("hello")),
    m_mF64(0.0)
{

}

Default ::
  Default(
      U32 mU32,
      const Fw::StringBase& mS1,
      F64 mF64
  ) :
    Serializable(),
    m_mU32(mU32),
    m_mS1(mS1),
    m_mF64(mF64)
{

}

Default ::
  Default(const Default& obj) :
    Serializable(),
    m_mU32(obj.m_mU32),
    m_mS1(obj.m_mS1),
    m_mF64(obj.m_mF64)
{

}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Default& Default ::
  operator=(const Default& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_mU32, obj.m_mS1, obj.m_mF64);
  return *this;
}

bool Default ::
  operator==(const Default& obj) const
{
  return (
    (this->m_mU32 == obj.m_mU32) &&
    (this->m_mS1 == obj.m_mS1) &&
    (this->m_mF64 == obj.m_mF64)
  );
}

bool Default ::
  operator!=(const Default& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Default& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Default ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_mU32);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_mS1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_mF64);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

Fw::SerializeStatus Default ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_mU32);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_mS1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_mF64);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void Default ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "mU32 = %" PRIu32 ", "
    "mS1 = %s, "
    "mF64 = %f"
    " )";

  sb.format(
    formatString,
    this->m_mU32,
    this->m_mS1.toChar(),
    this->m_mF64
  );
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void Default ::
  set(
      U32 mU32,
      const Fw::StringBase& mS1,
      F64 mF64
  )
{
  this->m_mU32 = mU32;
  this->m_mS1 = mS1;
  this->m_mF64 = mF64;
}

void Default ::
  setmU32(U32 mU32)
{
  this->m_mU32 = mU32;
}

void Default ::
  setmS1(const Fw::StringBase& mS1)
{
  this->m_mS1 = mS1;
}

void Default ::
  setmF64(F64 mF64)
{
  this->m_mF64 = mF64;
}
