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
        }
    }  
}
