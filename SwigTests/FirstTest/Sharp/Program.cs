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
           
            Console.Write("Done. Press any key to continue.");
            Console.ReadKey();
        }
    }  
}
