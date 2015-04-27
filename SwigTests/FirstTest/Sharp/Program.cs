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

            var myObject = new Object();

            var vec3 = new float3(1.1f, 2.2f, 3.3f);
           
            Console.Write(myObject.ray_cast(vec3, vec3, vec3, vec3, 2));
            Console.Write("Done. Press any key to continue.");
            Console.ReadKey();
        }
    }  
}
