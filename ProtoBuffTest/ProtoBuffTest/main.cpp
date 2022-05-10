#include <iostream>
#include <fstream>
#include <string>
#include "google/protobuf/compiler/importer.h"
#include <google/protobuf/dynamic_message.h>
#include "address.pb.h"
#include <sstream>

using namespace std;

// This function fills in a Person message based on user input.
//void PromptForAddress(tutorial::Person *person)
//{
//	cout << "Enter person ID number: ";
//	int id = 7;
//	//cin >> id;
//	person->set_id(id);
//	//cin.ignore(256, '\n');
//
//	cout << "Enter name: ";
//	//getline(cin, *person->mutable_name());
//	person->set_name("ab");
//
//	cout << "Enter email address (blank for none): ";
//	string email = "12@sina.com";
//	//getline(cin, email);
//	if (!email.empty())
//	{
//		person->set_email(email);
//	}
//
//	//while (true)
//	//{
//	//	cout << "Enter a phone number (or leave blank to finish): ";
//	//	string number;
//	//	getline(cin, number);
//	//	if (number.empty())
//	//	{
//	//		break;
//	//	}
//	//	// ＠＠＠ Person::PhoneNumber
//	//	tutorial::Person::PhoneNumber *phone_number = person->add_phones();
//	//	phone_number->set_number(number);
//
//	//	cout << "Is this a mobile, home, or work phone? ";
//	//	string type;
//	//	getline(cin, type);
//	//	if (type == "mobile")
//	//	{
//	//		// ＠＠＠ Person
//	//		phone_number->set_type(tutorial::Person::MOBILE);
//	//	}
//	//	else if (type == "home")
//	//	{
//	//		// ＠＠＠ Person
//	//		phone_number->set_type(tutorial::Person::HOME);
//	//	}
//	//	else if (type == "work")
//	//	{
//	//		// ＠＠＠ Person
//	//		phone_number->set_type(tutorial::Person::WORK);
//	//	}
//	//	else
//	//	{
//	//		cout << "Unknown phone type.  Using default." << endl;
//	//	}
//	//}
//}

//int WriteToFile(int argc, char *argv[])
//{
//	// Verify that the version of the library that we linked against is
//	// compatible with the version of the headers we compiled against.
//	GOOGLE_PROTOBUF_VERIFY_VERSION;
//
//	if (argc != 2)
//	{
//		cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
//		return -1;
//	}
//	// ＠＠＠ AddressBook
//	tutorial::AddressBook address_book;
//
//	{
//		// Read the existing address book.
//		fstream input(argv[1], ios::in | ios::binary);
//		if (!input)
//		{
//			cout << argv[1] << ": File not found.  Creating a new file." << endl;
//			// ＠＠＠ ParseFromIstream
//		}
//		else if (!address_book.ParseFromIstream(&input))
//		{
//			cerr << "Failed to parse address book." << endl;
//			return -1;
//		}
//	}
//
//	// Add an address.
//	PromptForAddress(address_book.add_people());
//
//	{
//		// Write the new address book back to disk.
//		fstream output(argv[1], ios::out | ios::trunc | ios::binary);
//		// ＠＠＠ SerializeToOstream
//		if (!address_book.SerializeToOstream(&output))
//		{
//			cerr << "Failed to write address book." << endl;
//			return -1;
//		}
//	}
//
//	
//
//	return 0;
//}


// Iterates though all people in the AddressBook and prints info about them.
//void ListPeople(const tutorial::AddressBook &address_book)
//{
//	for (int i = 0; i < address_book.people_size(); i++)
//	{
//		const tutorial::Person &person = address_book.people(i);
//
//		cout << "Person ID: " << person.id() << endl;
//		cout << "  Name: " << person.name() << endl;
//		if (person.has_email())
//		{
//			cout << "  E-mail address: " << person.email() << endl;
//		}
//
//		for (int j = 0; j < person.phones_size(); j++)
//		{
//			const tutorial::Person::PhoneNumber &phone_number = person.phones(j);
//
//			switch (phone_number.type())
//			{
//			case tutorial::Person::MOBILE:
//				cout << "  Mobile phone #: ";
//				break;
//			case tutorial::Person::HOME:
//				cout << "  Home phone #: ";
//				break;
//			case tutorial::Person::WORK:
//				cout << "  Work phone #: ";
//				break;
//			}
//			cout << phone_number.number() << endl;
//		}
//	}
//}

//int ReadFromFile(int argc, char *argv[])
//{
//	// Verify that the version of the library that we linked against is
//	// compatible with the version of the headers we compiled against.
//	GOOGLE_PROTOBUF_VERIFY_VERSION;
//
//	if (argc != 2)
//	{
//		cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
//		return -1;
//	}
//
//	tutorial::AddressBook address_book;
//
//	{
//		// Read the existing address book.
//		fstream input(argv[1], ios::in | ios::binary);
//		if (!address_book.ParseFromIstream(&input))
//		{
//			cerr << "Failed to parse address book." << endl;
//			return -1;
//		}
//	}
//
//	ListPeople(address_book);
//
//	return 0;
//}

void TestReflection()
{
	/* 反射创建实例 */
	//auto descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("tutorial.Person");
	const google::protobuf::Descriptor *descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("Person");
	const google::protobuf::Message *prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
	google::protobuf::Message *instance = prototype->New();

	/* 反射相关接口 */
	auto reflecter = instance->GetReflection();
	auto field = descriptor->FindFieldByName("name");
	reflecter->SetString(instance, field, "鸡你太美");

	// 获取属性的值.
	std::cout << reflecter->GetString(*instance, field) << std::endl;
}

int DynamicParseFromPBFile(const std::string &filename
	, const std::string &classname
	, std::function<void(::google::protobuf::Message *msg)> cb)
{

	//TODO 检查文件名是否合法
	auto pos = filename.find_last_of('/');
	std::string path;
	std::string file;
	if (pos == std::string::npos)
	{

		file = filename;
	}
	else
	{

		path = filename.substr(0, pos);
		file = filename.substr(pos + 1);
	}

	::google::protobuf::compiler::DiskSourceTree sourceTree;
	sourceTree.MapPath("", path);
	::google::protobuf::compiler::Importer importer(&sourceTree, NULL);
	importer.Import(file);
	const ::google::protobuf::Descriptor *descriptor = importer.pool()->FindMessageTypeByName(classname);
	if (!descriptor)
	{

		return 1;
	}
	::google::protobuf::DynamicMessageFactory factory;
	const ::google::protobuf::Message *message = factory.GetPrototype(descriptor);
	if (!message)
	{

		return 2;
	}
	::google::protobuf::Message *msg = message->New();
	if (!msg)
	{

		return 3;
	}
	auto reflecter = msg->GetReflection();
	auto field = descriptor->FindFieldByName("someName");
	reflecter->SetString(msg, field, "鸡你太美");
	std::cout << reflecter->GetString(*msg, field) << std::endl;

	cb(msg);
	delete msg;
	return 0;
}

int DynamicParseFromPBString(const std::string &proto_string
	, const std::string &classname
	, std::function<void(::google::protobuf::Message *msg)> cb)
{

	std::stringstream ss;
	ss << "/tmp/dps_" << rand() << "_" << rand() << ".proto";
	std::ofstream ofs(ss.str());
	ofs << proto_string;
	ofs.close();
	return DynamicParseFromPBFile(ss.str(), classname, cb);
}

void TestReadProtoFromFile()
{
	
	std::string pb_str;
	//从文件中sylar.proto中的sylar.XX类，解析上面测试类的序列化二进制
	//并输出序列化后的sylar.XX的信息
	DynamicParseFromPBFile("readFromFile.proto", "CustomFileMessage", [pb_str](::google::protobuf::Message *msg)
		{
			if (msg->ParseFromString(pb_str))
			{

				std::cout << msg->DebugString() << std::endl;
			}
		});
	std::cout << "===============================" << std::endl;
	

	//字符串pb文件内容
	std::string pbstr = "package xx;\n"
		"message BB { \n"
		"    optional string name = 1; \n"
		"    optional int32 age = 2; \n"
		"} \n"
		"message TT { \n"
		"    optional string name = 1; \n"
		"    optional int32 age = 2; \n"
		"    repeated string phones = 3; \n"
		"    repeated BB aa = 4; \n"
		"}";

	std::cout << "===============================" << std::endl;
	//pbstr的proto信息中的xx.TT，解析上面测试类的序列化二进制
	//并输出序列化后的xx.TT的信息
	DynamicParseFromPBString(pbstr, "xx.TT"
		, [pb_str](::google::protobuf::Message *msg)
		{

			if (msg->ParseFromString(pb_str))
			{

				std::cout << msg->DebugString() << std::endl;
			}
		});

}

// Main function:  Reads the entire address book from a file,s
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char *argv[])
{

	//WriteToFile(argc, argv);
	//ReadFromFile(argc, argv);

	//TestReflection();

	TestReadProtoFromFile();

	// Optional:  Delete all global objects allocated by libprotobuf.
	// ＠＠＠ ShutdownProtobufLibrary
	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}



