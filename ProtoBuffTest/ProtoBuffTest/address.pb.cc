// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: address.proto

#include "address.pb.h"

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

PROTOBUF_CONSTEXPR Person::Person(
	::_pbi::ConstantInitialized)
	: name_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
{
}
struct PersonDefaultTypeInternal
{
	PROTOBUF_CONSTEXPR PersonDefaultTypeInternal()
		: _instance(::_pbi::ConstantInitialized{})
	{
	}
	~PersonDefaultTypeInternal() {}
	union
	{
		Person _instance;
	};
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;
static ::_pb::Metadata file_level_metadata_address_2eproto[1];
static constexpr ::_pb::EnumDescriptor const **file_level_enum_descriptors_address_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const **file_level_service_descriptors_address_2eproto = nullptr;

const uint32_t TableStruct_address_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::Person, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::Person, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Person, name_),
  0,
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, -1, sizeof(::Person)},
};

static const ::_pb::Message *const file_default_instances[] = {
  &::_Person_default_instance_._instance,
};

const char descriptor_table_protodef_address_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
"\n\raddress.proto\"\026\n\006Person\022\014\n\004name\030\001 \002(\t"
;
static ::_pbi::once_flag descriptor_table_address_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_address_2eproto = {
	false, false, 39, descriptor_table_protodef_address_2eproto,
	"address.proto",
	&descriptor_table_address_2eproto_once, nullptr, 0, 1,
	schemas, file_default_instances, TableStruct_address_2eproto::offsets,
	file_level_metadata_address_2eproto, file_level_enum_descriptors_address_2eproto,
	file_level_service_descriptors_address_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable *descriptor_table_address_2eproto_getter()
{
	return &descriptor_table_address_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_address_2eproto(&descriptor_table_address_2eproto);

// ===================================================================

class Person::_Internal
{
public:
	using HasBits = decltype(std::declval<Person>()._has_bits_);
	static void set_has_name(HasBits *has_bits)
	{
		(*has_bits)[0] |= 1u;
	}
	static bool MissingRequiredFields(const HasBits &has_bits)
	{
		return ((has_bits[0] & 0x00000001) ^ 0x00000001) != 0;
	}
};

Person::Person(::PROTOBUF_NAMESPACE_ID::Arena *arena,
	bool is_message_owned)
	: ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned)
{
	SharedCtor();
	// @@protoc_insertion_point(arena_constructor:Person)
}
Person::Person(const Person &from)
	: ::PROTOBUF_NAMESPACE_ID::Message(),
	_has_bits_(from._has_bits_)
{
	_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
	name_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
	if (from._internal_has_name())
	{
		name_.Set(from._internal_name(),
			GetArenaForAllocation());
	}
	// @@protoc_insertion_point(copy_constructor:Person)
}

inline void Person::SharedCtor()
{
	name_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Person::~Person()
{
	// @@protoc_insertion_point(destructor:Person)
	if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>())
	{
		(void)arena;
		return;
	}
	SharedDtor();
}

inline void Person::SharedDtor()
{
	GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
	name_.Destroy();
}

void Person::SetCachedSize(int size) const
{
	_cached_size_.Set(size);
}

void Person::Clear()
{
	// @@protoc_insertion_point(message_clear_start:Person)
	uint32_t cached_has_bits = 0;
	// Prevent compiler warnings about cached_has_bits being unused
	(void)cached_has_bits;

	cached_has_bits = _has_bits_[0];
	if (cached_has_bits & 0x00000001u)
	{
		name_.ClearNonDefaultToEmpty();
	}
	_has_bits_.Clear();
	_internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char *Person::_InternalParse(const char *ptr, ::_pbi::ParseContext *ctx)
{
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
	_Internal::HasBits has_bits{};
	while (!ctx->Done(&ptr))
	{
		uint32_t tag;
		ptr = ::_pbi::ReadTag(ptr, &tag);
		switch (tag >> 3)
		{
			// required string name = 1;
		case 1:
			if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10))
			{
				auto str = _internal_mutable_name();
				ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
				CHK_(ptr);
#ifndef NDEBUG
				::_pbi::VerifyUTF8(str, "Person.name");
#endif  // !NDEBUG
			}
			else
				goto handle_unusual;
			continue;
		default:
			goto handle_unusual;
		}  // switch
	handle_unusual:
		if ((tag == 0) || ((tag & 7) == 4))
		{
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
	_has_bits_.Or(has_bits);
	return ptr;
failure:
	ptr = nullptr;
	goto message_done;
#undef CHK_
}

uint8_t *Person::_InternalSerialize(
	uint8_t *target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream *stream) const
{
	// @@protoc_insertion_point(serialize_to_array_start:Person)
	uint32_t cached_has_bits = 0;
	(void)cached_has_bits;

	cached_has_bits = _has_bits_[0];
	// required string name = 1;
	if (cached_has_bits & 0x00000001u)
	{
		::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
			this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
			::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
			"Person.name");
		target = stream->WriteStringMaybeAliased(
			1, this->_internal_name(), target);
	}

	if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields()))
	{
		target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
			_internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
	}
	// @@protoc_insertion_point(serialize_to_array_end:Person)
	return target;
}

size_t Person::ByteSizeLong() const
{
	// @@protoc_insertion_point(message_byte_size_start:Person)
	size_t total_size = 0;

	// required string name = 1;
	if (_internal_has_name())
	{
		total_size += 1 +
			::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
				this->_internal_name());
	}
	uint32_t cached_has_bits = 0;
	// Prevent compiler warnings about cached_has_bits being unused
	(void)cached_has_bits;

	return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person::_class_data_ = {
	::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
	Person::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData *Person::GetClassData() const { return &_class_data_; }

void Person::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message *to,
	const ::PROTOBUF_NAMESPACE_ID::Message &from)
{
	static_cast<Person *>(to)->MergeFrom(
		static_cast<const Person &>(from));
}


void Person::MergeFrom(const Person &from)
{
	// @@protoc_insertion_point(class_specific_merge_from_start:Person)
	GOOGLE_DCHECK_NE(&from, this);
	uint32_t cached_has_bits = 0;
	(void)cached_has_bits;

	if (from._internal_has_name())
	{
		_internal_set_name(from._internal_name());
	}
	_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person &from)
{
	// @@protoc_insertion_point(class_specific_copy_from_start:Person)
	if (&from == this) return;
	Clear();
	MergeFrom(from);
}

bool Person::IsInitialized() const
{
	if (_Internal::MissingRequiredFields(_has_bits_)) return false;
	return true;
}

void Person::InternalSwap(Person *other)
{
	using std::swap;
	auto *lhs_arena = GetArenaForAllocation();
	auto *rhs_arena = other->GetArenaForAllocation();
	_internal_metadata_.InternalSwap(&other->_internal_metadata_);
	swap(_has_bits_[0], other->_has_bits_[0]);
	::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
		&name_, lhs_arena,
		&other->name_, rhs_arena
	);
}

::PROTOBUF_NAMESPACE_ID::Metadata Person::GetMetadata() const
{
	return ::_pbi::AssignDescriptors(
		&descriptor_table_address_2eproto_getter, &descriptor_table_address_2eproto_once,
		file_level_metadata_address_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE::Person *
Arena::CreateMaybeMessage< ::Person >(Arena *arena)
{
	return Arena::CreateMessageInternal< ::Person >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
