using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp
{
    class Program
    {
        static void Main(string[] args)
        {

            var cpp = new cpp_file();
            Console.WriteLine(cpp.times2(5));

            var vec = new btVector3(1,2,3);
            Console.WriteLine("btVector3: " + vec.getX()+","+vec.getY()+","+vec.getZ());
            Console.Write("Done. Press any key to continue.");
            Console.ReadKey();
        }
    }  
}
