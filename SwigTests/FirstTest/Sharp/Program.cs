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
            var bools = new bool[20];
            for (int i = 0; i < 20; i++)
            {
                bools[i] = true;
            }

            
            var floats = new float[24];
            for (int i = 0; i < 24; i++)
            {
                floats[i] = 7.7f;
            }

            var ints = new int[3];
            for (int i = 0; i < 3; i++)
            {
                ints[i] =i;
            }

            //testing general float[]
            var floatN = new float[4];
            for (int i = 0; i < 4; i++)
            {
                floatN[i] = 1.1f;
            }
            myObject.color(floatN);

            myObject.mode(Object.mode_enum.mode_EDIT);
            Console.WriteLine(myObject.layers());

            string myString = "test";
            myObject.active_material_index(5);
            //Console.WriteLine(myObject.layers(bools));
            int myInt = 5;
            //myObject.ray_cast(vec3, vec3, vec3, vec3, myInt);
            Console.Write("Done. Press any key to continue.");
            Console.ReadKey();
        }
    }  
}
