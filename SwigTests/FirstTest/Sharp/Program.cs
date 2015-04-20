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

            var cpp = new cpp_file();
            float3 vec = new float3(1,2,3);
            Console.WriteLine(cpp.test1(ref vec));
           
            Console.Write("Done. Press any key to continue.");
            Console.ReadKey();
        }
    }  
}
