// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: address.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_address_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_address_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_address_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal
{
	class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_address_2eproto
{
	static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_address_2eproto;
class Person;
struct PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Person *Arena::CreateMaybeMessage<::Person>(Arena *);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Person final :
	public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Person) */
{
public:
	inline Person() : Person(nullptr) {}
	~Person() override;
	explicit PROTOBUF_CONSTEXPR Person(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

	Person(const Person &from);
	Person(Person &&from) noexcept
		: Person()
	{
		*this = ::std::move(from);
	}

	inline Person &operator=(const Person &from)
	{
		CopyFrom(from);
		return *this;
	}
	inline Person &operator=(Person &&from) noexcept
	{
		if (this == &from) return *this;
		if (GetOwningArena() == from.GetOwningArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
			&& GetOwningArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
			)
		{
			InternalSwap(&from);
		}
		else
		{
			CopyFrom(from);
		}
		return *this;
	}

	inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet &unknown_fields() const
	{
		return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
	}
	inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet *mutable_unknown_fields()
	{
		return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
	}

	static const ::PROTOBUF_NAMESPACE_ID::Descriptor *descriptor()
	{
		return GetDescriptor();
	}
	static const ::PROTOBUF_NAMESPACE_ID::Descriptor *GetDescriptor()
	{
		return default_instance().GetMetadata().descriptor;
	}
	static const ::PROTOBUF_NAMESPACE_ID::Reflection *GetReflection()
	{
		return default_instance().GetMetadata().reflection;
	}
	static const Person &default_instance()
	{
		return *internal_default_instance();
	}
	static inline const Person *internal_default_instance()
	{
		return reinterpret_cast<const Person *>(
			&_Person_default_instance_);
	}
	static constexpr int kIndexInFileMessages =
		0;

	friend void swap(Person &a, Person &b)
	{
		a.Swap(&b);
	}
	inline void Swap(Person *other)
	{
		if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
		if (GetOwningArena() != nullptr &&
			GetOwningArena() == other->GetOwningArena())
		{
#else  // PROTOBUF_FORCE_COPY_IN_SWAP
		if (GetOwningArena() == other->GetOwningArena())
		{
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
			InternalSwap(other);
		}
		else
		{
			::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
		}
		}
	void UnsafeArenaSwap(Person * other)
	{
		if (other == this) return;
		GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
		InternalSwap(other);
	}

	// implements Message ----------------------------------------------

	Person *New(::PROTOBUF_NAMESPACE_ID::Arena * arena = nullptr) const final
	{
		return CreateMaybeMessage<Person>(arena);
	}
	using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
	void CopyFrom(const Person & from);
	using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
	void MergeFrom(const Person & from);
private:
	static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message * to, const ::PROTOBUF_NAMESPACE_ID::Message & from);
public:
	PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
	bool IsInitialized() const final;

	size_t ByteSizeLong() const final;
	const char *_InternalParse(const char *ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext * ctx) final;
	uint8_t *_InternalSerialize(
		uint8_t * target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream * stream) const final;
	int GetCachedSize() const final { return _cached_size_.Get(); }

private:
	void SharedCtor();
	void SharedDtor();
	void SetCachedSize(int size) const final;
	void InternalSwap(Person * other);

private:
	friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
	static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
	{
		return "Person";
	}
protected:
	explicit Person(::PROTOBUF_NAMESPACE_ID::Arena * arena,
		bool is_message_owned = false);
public:

	static const ClassData _class_data_;
	const ::PROTOBUF_NAMESPACE_ID::Message::ClassData *GetClassData() const final;

	::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

	// nested types ----------------------------------------------------

	// accessors -------------------------------------------------------

	enum : int
	{
		kNameFieldNumber = 1,
	};
	// required string name = 1;
	bool has_name() const;
private:
	bool _internal_has_name() const;
public:
	void clear_name();
	const std::string &name() const;
	template <typename ArgT0 = const std::string &, typename... ArgT>
	void set_name(ArgT0 && arg0, ArgT... args);
	std::string *mutable_name();
	PROTOBUF_NODISCARD std::string *release_name();
	void set_allocated_name(std::string * name);
private:
	const std::string &_internal_name() const;
	inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string & value);
	std::string *_internal_mutable_name();
public:

	// @@protoc_insertion_point(class_scope:Person)
private:
	class _Internal;

	template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
	typedef void InternalArenaConstructable_;
	typedef void DestructorSkippable_;
	::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
	mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
	::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
	friend struct ::TableStruct_address_2eproto;
	};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Person

// required string name = 1;
inline bool Person::_internal_has_name() const
{
	bool value = (_has_bits_[0] & 0x00000001u) != 0;
	return value;
}
inline bool Person::has_name() const
{
	return _internal_has_name();
}
inline void Person::clear_name()
{
	name_.ClearToEmpty();
	_has_bits_[0] &= ~0x00000001u;
}
inline const std::string &Person::name() const
{
	// @@protoc_insertion_point(field_get:Person.name)
	return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Person::set_name(ArgT0 &&arg0, ArgT... args)
{
	_has_bits_[0] |= 0x00000001u;
	name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
	// @@protoc_insertion_point(field_set:Person.name)
}
inline std::string *Person::mutable_name()
{
	std::string *_s = _internal_mutable_name();
	// @@protoc_insertion_point(field_mutable:Person.name)
	return _s;
}
inline const std::string &Person::_internal_name() const
{
	return name_.Get();
}
inline void Person::_internal_set_name(const std::string &value)
{
	_has_bits_[0] |= 0x00000001u;
	name_.Set(value, GetArenaForAllocation());
}
inline std::string *Person::_internal_mutable_name()
{
	_has_bits_[0] |= 0x00000001u;
	return name_.Mutable(GetArenaForAllocation());
}
inline std::string *Person::release_name()
{
	// @@protoc_insertion_point(field_release:Person.name)
	if (!_internal_has_name())
	{
		return nullptr;
	}
	_has_bits_[0] &= ~0x00000001u;
	auto *p = name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	if (name_.IsDefault())
	{
		name_.Set("", GetArenaForAllocation());
	}
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
	return p;
}
inline void Person::set_allocated_name(std::string *name)
{
	if (name != nullptr)
	{
		_has_bits_[0] |= 0x00000001u;
	}
	else
	{
		_has_bits_[0] &= ~0x00000001u;
	}
	name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	if (name_.IsDefault())
	{
		name_.Set("", GetArenaForAllocation());
	}
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
	// @@protoc_insertion_point(field_set_allocated:Person.name)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_address_2eproto
