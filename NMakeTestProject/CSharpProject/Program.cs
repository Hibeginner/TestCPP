using System;
using DependentProject;

namespace CSharpProject
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            DependentProject.Tools tools = new DependentProject.Tools();
            tools.name = "Test Tool";
            tools.sayName();
        }
    }
}
