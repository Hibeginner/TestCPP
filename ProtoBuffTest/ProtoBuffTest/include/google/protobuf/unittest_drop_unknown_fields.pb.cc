// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_drop_unknown_fields.proto

#include "google/protobuf/unittest_drop_unknown_fields.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace unittest_drop_unknown_fields {
PROTOBUF_CONSTEXPR Foo::Foo(
    ::_pbi::ConstantInitialized)
  : int32_value_(0)
  , enum_value_(0)
{}
struct FooDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FooDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~FooDefaultTypeInternal() {}
  union {
    Foo _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FooDefaultTypeInternal _Foo_default_instance_;
PROTOBUF_CONSTEXPR FooWithExtraFields::FooWithExtraFields(
    ::_pbi::ConstantInitialized)
  : int32_value_(0)
  , enum_value_(0)

  , extra_int32_value_(0){}
struct FooWithExtraFieldsDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FooWithExtraFieldsDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~FooWithExtraFieldsDefaultTypeInternal() {}
  union {
    FooWithExtraFields _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FooWithExtraFieldsDefaultTypeInternal _FooWithExtraFields_default_instance_;
}  // namespace unittest_drop_unknown_fields
static ::_pb::Metadata file_level_metadata_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto[2];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto[2];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto = nullptr;

const uint32_t TableStruct_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::unittest_drop_unknown_fields::Foo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::unittest_drop_unknown_fields::Foo, int32_value_),
  PROTOBUF_FIELD_OFFSET(::unittest_drop_unknown_fields::Foo, enum_value_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::unittest_drop_unknown_fields::FooWithExtraFields, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::unittest_drop_unknown_fields::FooWithExtraFields, int32_value_),
  PROTOBUF_FIELD_OFFSET(::unittest_drop_unknown_fields::FooWithExtraFields, enum_value_),
  PROTOBUF_FIELD_OFFSET(::unittest_drop_unknown_fields::FooWithExtraFields, extra_int32_value_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::unittest_drop_unknown_fields::Foo)},
  { 8, -1, -1, sizeof(::unittest_drop_unknown_fields::FooWithExtraFields)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::unittest_drop_unknown_fields::_Foo_default_instance_._instance,
  &::unittest_drop_unknown_fields::_FooWithExtraFields_default_instance_._instance,
};

const char descriptor_table_protodef_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n2google/protobuf/unittest_drop_unknown_"
  "fields.proto\022\034unittest_drop_unknown_fiel"
  "ds\"\205\001\n\003Foo\022\023\n\013int32_value\030\001 \001(\005\022@\n\nenum_"
  "value\030\002 \001(\0162,.unittest_drop_unknown_fiel"
  "ds.Foo.NestedEnum\"\'\n\nNestedEnum\022\007\n\003FOO\020\000"
  "\022\007\n\003BAR\020\001\022\007\n\003BAZ\020\002\"\307\001\n\022FooWithExtraField"
  "s\022\023\n\013int32_value\030\001 \001(\005\022O\n\nenum_value\030\002 \001"
  "(\0162;.unittest_drop_unknown_fields.FooWit"
  "hExtraFields.NestedEnum\022\031\n\021extra_int32_v"
  "alue\030\003 \001(\005\"0\n\nNestedEnum\022\007\n\003FOO\020\000\022\007\n\003BAR"
  "\020\001\022\007\n\003BAZ\020\002\022\007\n\003QUX\020\003B,\242\002\014DropUnknowns\252\002\032"
  "Google.Protobuf.TestProtosb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto = {
    false, false, 474, descriptor_table_protodef_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto,
    "google/protobuf/unittest_drop_unknown_fields.proto",
    &descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto::offsets,
    file_level_metadata_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto, file_level_enum_descriptors_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto,
    file_level_service_descriptors_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto_getter() {
  return &descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto(&descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto);
namespace unittest_drop_unknown_fields {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Foo_NestedEnum_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto);
  return file_level_enum_descriptors_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto[0];
}
bool Foo_NestedEnum_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Foo_NestedEnum Foo::FOO;
constexpr Foo_NestedEnum Foo::BAR;
constexpr Foo_NestedEnum Foo::BAZ;
constexpr Foo_NestedEnum Foo::NestedEnum_MIN;
constexpr Foo_NestedEnum Foo::NestedEnum_MAX;
constexpr int Foo::NestedEnum_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* FooWithExtraFields_NestedEnum_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto);
  return file_level_enum_descriptors_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto[1];
}
bool FooWithExtraFields_NestedEnum_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr FooWithExtraFields_NestedEnum FooWithExtraFields::FOO;
constexpr FooWithExtraFields_NestedEnum FooWithExtraFields::BAR;
constexpr FooWithExtraFields_NestedEnum FooWithExtraFields::BAZ;
constexpr FooWithExtraFields_NestedEnum FooWithExtraFields::QUX;
constexpr FooWithExtraFields_NestedEnum FooWithExtraFields::NestedEnum_MIN;
constexpr FooWithExtraFields_NestedEnum FooWithExtraFields::NestedEnum_MAX;
constexpr int FooWithExtraFields::NestedEnum_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class Foo::_Internal {
 public:
};

Foo::Foo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:unittest_drop_unknown_fields.Foo)
}
Foo::Foo(const Foo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&int32_value_, &from.int32_value_,
    static_cast<size_t>(reinterpret_cast<char*>(&enum_value_) -
    reinterpret_cast<char*>(&int32_value_)) + sizeof(enum_value_));
  // @@protoc_insertion_point(copy_constructor:unittest_drop_unknown_fields.Foo)
}

inline void Foo::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&int32_value_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&enum_value_) -
    reinterpret_cast<char*>(&int32_value_)) + sizeof(enum_value_));
}

Foo::~Foo() {
  // @@protoc_insertion_point(destructor:unittest_drop_unknown_fields.Foo)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Foo::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Foo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Foo::Clear() {
// @@protoc_insertion_point(message_clear_start:unittest_drop_unknown_fields.Foo)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&int32_value_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&enum_value_) -
      reinterpret_cast<char*>(&int32_value_)) + sizeof(enum_value_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Foo::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 int32_value = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          int32_value_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .unittest_drop_unknown_fields.Foo.NestedEnum enum_value = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_enum_value(static_cast<::unittest_drop_unknown_fields::Foo_NestedEnum>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Foo::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:unittest_drop_unknown_fields.Foo)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 int32_value = 1;
  if (this->_internal_int32_value() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_int32_value(), target);
  }

  // .unittest_drop_unknown_fields.Foo.NestedEnum enum_value = 2;
  if (this->_internal_enum_value() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_enum_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:unittest_drop_unknown_fields.Foo)
  return target;
}

size_t Foo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:unittest_drop_unknown_fields.Foo)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 int32_value = 1;
  if (this->_internal_int32_value() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_int32_value());
  }

  // .unittest_drop_unknown_fields.Foo.NestedEnum enum_value = 2;
  if (this->_internal_enum_value() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_enum_value());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Foo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Foo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Foo::GetClassData() const { return &_class_data_; }

void Foo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Foo *>(to)->MergeFrom(
      static_cast<const Foo &>(from));
}


void Foo::MergeFrom(const Foo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:unittest_drop_unknown_fields.Foo)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_int32_value() != 0) {
    _internal_set_int32_value(from._internal_int32_value());
  }
  if (from._internal_enum_value() != 0) {
    _internal_set_enum_value(from._internal_enum_value());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Foo::CopyFrom(const Foo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:unittest_drop_unknown_fields.Foo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Foo::IsInitialized() const {
  return true;
}

void Foo::InternalSwap(Foo* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Foo, enum_value_)
      + sizeof(Foo::enum_value_)
      - PROTOBUF_FIELD_OFFSET(Foo, int32_value_)>(
          reinterpret_cast<char*>(&int32_value_),
          reinterpret_cast<char*>(&other->int32_value_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Foo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto_getter, &descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto_once,
      file_level_metadata_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto[0]);
}

// ===================================================================

class FooWithExtraFields::_Internal {
 public:
};

FooWithExtraFields::FooWithExtraFields(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:unittest_drop_unknown_fields.FooWithExtraFields)
}
FooWithExtraFields::FooWithExtraFields(const FooWithExtraFields& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&int32_value_, &from.int32_value_,
    static_cast<size_t>(reinterpret_cast<char*>(&extra_int32_value_) -
    reinterpret_cast<char*>(&int32_value_)) + sizeof(extra_int32_value_));
  // @@protoc_insertion_point(copy_constructor:unittest_drop_unknown_fields.FooWithExtraFields)
}

inline void FooWithExtraFields::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&int32_value_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&extra_int32_value_) -
    reinterpret_cast<char*>(&int32_value_)) + sizeof(extra_int32_value_));
}

FooWithExtraFields::~FooWithExtraFields() {
  // @@protoc_insertion_point(destructor:unittest_drop_unknown_fields.FooWithExtraFields)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void FooWithExtraFields::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void FooWithExtraFields::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void FooWithExtraFields::Clear() {
// @@protoc_insertion_point(message_clear_start:unittest_drop_unknown_fields.FooWithExtraFields)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&int32_value_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&extra_int32_value_) -
      reinterpret_cast<char*>(&int32_value_)) + sizeof(extra_int32_value_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FooWithExtraFields::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 int32_value = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          int32_value_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .unittest_drop_unknown_fields.FooWithExtraFields.NestedEnum enum_value = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_enum_value(static_cast<::unittest_drop_unknown_fields::FooWithExtraFields_NestedEnum>(val));
        } else
          goto handle_unusual;
        continue;
      // int32 extra_int32_value = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          extra_int32_value_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* FooWithExtraFields::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:unittest_drop_unknown_fields.FooWithExtraFields)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 int32_value = 1;
  if (this->_internal_int32_value() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_int32_value(), target);
  }

  // .unittest_drop_unknown_fields.FooWithExtraFields.NestedEnum enum_value = 2;
  if (this->_internal_enum_value() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_enum_value(), target);
  }

  // int32 extra_int32_value = 3;
  if (this->_internal_extra_int32_value() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_extra_int32_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:unittest_drop_unknown_fields.FooWithExtraFields)
  return target;
}

size_t FooWithExtraFields::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:unittest_drop_unknown_fields.FooWithExtraFields)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 int32_value = 1;
  if (this->_internal_int32_value() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_int32_value());
  }

  // .unittest_drop_unknown_fields.FooWithExtraFields.NestedEnum enum_value = 2;
  if (this->_internal_enum_value() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_enum_value());
  }

  // int32 extra_int32_value = 3;
  if (this->_internal_extra_int32_value() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_extra_int32_value());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FooWithExtraFields::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    FooWithExtraFields::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FooWithExtraFields::GetClassData() const { return &_class_data_; }

void FooWithExtraFields::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<FooWithExtraFields *>(to)->MergeFrom(
      static_cast<const FooWithExtraFields &>(from));
}


void FooWithExtraFields::MergeFrom(const FooWithExtraFields& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:unittest_drop_unknown_fields.FooWithExtraFields)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_int32_value() != 0) {
    _internal_set_int32_value(from._internal_int32_value());
  }
  if (from._internal_enum_value() != 0) {
    _internal_set_enum_value(from._internal_enum_value());
  }
  if (from._internal_extra_int32_value() != 0) {
    _internal_set_extra_int32_value(from._internal_extra_int32_value());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void FooWithExtraFields::CopyFrom(const FooWithExtraFields& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:unittest_drop_unknown_fields.FooWithExtraFields)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FooWithExtraFields::IsInitialized() const {
  return true;
}

void FooWithExtraFields::InternalSwap(FooWithExtraFields* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(FooWithExtraFields, extra_int32_value_)
      + sizeof(FooWithExtraFields::extra_int32_value_)
      - PROTOBUF_FIELD_OFFSET(FooWithExtraFields, int32_value_)>(
          reinterpret_cast<char*>(&int32_value_),
          reinterpret_cast<char*>(&other->int32_value_));
}

::PROTOBUF_NAMESPACE_ID::Metadata FooWithExtraFields::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto_getter, &descriptor_table_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto_once,
      file_level_metadata_google_2fprotobuf_2funittest_5fdrop_5funknown_5ffields_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace unittest_drop_unknown_fields
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::unittest_drop_unknown_fields::Foo*
Arena::CreateMaybeMessage< ::unittest_drop_unknown_fields::Foo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::unittest_drop_unknown_fields::Foo >(arena);
}
template<> PROTOBUF_NOINLINE ::unittest_drop_unknown_fields::FooWithExtraFields*
Arena::CreateMaybeMessage< ::unittest_drop_unknown_fields::FooWithExtraFields >(Arena* arena) {
  return Arena::CreateMessageInternal< ::unittest_drop_unknown_fields::FooWithExtraFields >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>