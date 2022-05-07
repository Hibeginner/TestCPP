using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpTest
{
    class ClassA
    {
        private ClassB classB = null;

        public ClassA()
        {
            Console.WriteLine("ClassA construct: " + classB);
        }
    }
}
