using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpGCExample
{
    public class Person : IDisposable
    {
        public Person(int size)
        {
            grades = new int[size];
            Console.WriteLine("Ran constructor");
        }
        ~Person()
        {
            Console.WriteLine("Ran finalizer");
        }
        public int[] grades;

        public void Dispose()
        {
            Console.WriteLine("Ran dispose");
        }
    }
}
