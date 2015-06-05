using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Fusee.Math;

namespace Sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var myCpp = new cpp_file();
            var vec = new float3(1.1f, 2.2f, 3.3f);


            Console.WriteLine("----------------------------------------------------");
            Console.WriteLine("Pure Foo" );
            Console.WriteLine("----------------------------------------------------");

            myCpp.testFooIn(new Foo());
            var theFoo = myCpp.testFooOut();
            var foo = myCpp.testFooInOut(theFoo);
            
            Console.WriteLine("----------------------------------------------------");

            Console.WriteLine(""+"\n");
            Console.WriteLine("----------------------------------------------------");
            Console.WriteLine("Pure Array tp float3");
            Console.WriteLine("----------------------------------------------------");
            myCpp.testArrayIn(vec);
            var a = myCpp.testArrayOut();
            var a1 = myCpp.testArrayInOut(vec);
            Console.WriteLine("----------------------------------------------------");

            Console.WriteLine("" + "\n");
            Console.WriteLine("----------------------------------------------------");
            Console.WriteLine("Mixed");
            Console.WriteLine("----------------------------------------------------");
            var fout = myCpp.ArrayInFooOut(vec);
            fout.talk();

            //var aOut = myCpp.FooInArrayOut(theFoo);
            Console.WriteLine("----------------------------------------------------");

            Console.Write("Done. Press any key to continue.");
            Console.ReadKey();
        }
    }  
}
