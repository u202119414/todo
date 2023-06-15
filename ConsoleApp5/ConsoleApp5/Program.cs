using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ConsoleApp5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int cantidadE=-1;
            do
            {
                Console.Clear();
                Console.WriteLine("Cantidad de empleados");
                string cantidadempleados = Console.ReadLine();
                cantidadE = int.Parse(cantidadempleados);
            } while (cantidadE<0);
            Console.WriteLine("Leyenda:");
            Console.WriteLine("Puesto de trabajo:Operario, Supervisor o Administrador");
            Console.WriteLine("Mes del pago de plantilla");

            string mess=Console.ReadLine();
            string mes = mess.ToUpper();
            Console.Clear();
            string[] nombres = new string[cantidadE];
            string[] puestos = new string[cantidadE];
            string[] pension = new string[cantidadE];
            int[] tiempo = new int[cantidadE];
           // int[] sueldo = new int[cantidadE];
            double[] sueldoss = new double[cantidadE];
            for (int i=0;i<cantidadE;i++)
            {
                tiempo[i] = -1; 
            }
            string nombre;
            string puesto;
            string pensionn;
            for (int i=0;i<cantidadE;i++)
            {
                do { 
                    
                    Console.WriteLine("Nombre del empleado"+ (i + 1)+ ":");
                    nombre = Console.ReadLine();
                    nombres[i] = nombre.ToUpper();
                    Console.WriteLine("Puesto de trabajo del empleado"+ (i + 1)+ ":");
                    puesto = Console.ReadLine();
                    puestos[i] = puesto.ToUpper();
                    Console.WriteLine("Tipo de pensión del empleado"+ (i + 1), ":");
                    pensionn = Console.ReadLine();
                    pension[i] = pensionn.ToUpper();

                    Console.WriteLine("Tiempo de servicio del empleado"+ (i + 1)+ ":");
                    tiempo[i] = int.Parse(Console.ReadLine());



                    Console.Clear();
                    if (nombres[i] == "" || puestos[i] == "" || pension[i] == "" || tiempo[i] == -1)
                    { Console.WriteLine("Faltó escribir un dato"); }

                } while (nombres[i] == "" || puestos[i] == "" || pension[i] == "" || tiempo[i]==-1);
             

              
            }

            for (int i=0;i<cantidadE;i++)//puestos
            {

                if (puestos[i] == "OPERARIO")
                {
                    sueldoss[i] = 1000;
                }
                else {if (puestos[i] == "SUPERVISOR")
                    { sueldoss[i] = 2000; }
                    else { if (puestos[i] == "ADMINISTRADOR") { sueldoss[i] = 4000; } }
                        
                  }
            
            }

            for (int i = 0; i < cantidadE; i++) //tiempo
            {
                if (tiempo[i] ==25)
                { sueldoss[i] = sueldoss[i] *2; }
                else { if (tiempo[i] == 30) { sueldoss[i] = sueldoss[i] * 3; } }
            
            }
        
            for (int i = 0; i < cantidadE; i++)//pension
            {
                if (pension[i] == "OPN")
                {
                    if (tiempo[i] == 25)
                    { sueldoss[i] = (sueldoss[i] / 2) + ((sueldoss[i] / 2) * (1 - 0.13)); }
                    else
                    {
                        if (tiempo[i] == 30) { sueldoss[i] = (sueldoss[i] / 3) + ((sueldoss[i] / 3) * (1 - 0.13)); }
                        else { sueldoss[i] = sueldoss[i] * (1 - 0.13); }
                    }
                }
                else
                {
                    if (tiempo[i] == 25)
                    { sueldoss[i] = (sueldoss[i] / 2) + ((sueldoss[i] / 2) * (1 - 0.10)); }
                    else
                    {
                        if (tiempo[i] == 30) { sueldoss[i] = (sueldoss[i] / 3) + ((sueldoss[i] / 3) * (1 - 0.10)); }
                        else { sueldoss[i] = sueldoss[i] * (1 - 0.10); }
                    }

                }
            }
            for (int i = 0; i < cantidadE; i++) //CTS
            {
                if (mes == "JULIO" || mes == "DICIEMBRE")
                { sueldoss[i] = sueldoss[i] + sueldoss[i]; }
            }
            for (int i = 0; i < cantidadE; i++) //
            {
                for (int j = 0; j < cantidadE; j++)
                {
                    if (sueldoss[i] > sueldoss[j])
                    { 
                        
                        
                        double temp = sueldoss[i];
                        string nombtemp = nombres[i];
                        sueldoss[i] = sueldoss[j];
                        nombres[i] = nombres[j];
                        sueldoss[j] = temp;
                        nombres[j] = nombtemp;
                    
                    
                    }
                }
            }
            double suma=0;
            for (int i = 0; i < cantidadE; i++)
            {
                suma = suma + sueldoss[i];
            }
            double promedio = suma / cantidadE;
            Console.WriteLine("Listado según su sueldo");
            for (int i =0;i<cantidadE;i++)
            {
                Console.WriteLine(nombres[i] + sueldoss[i]);

            }
            Console.WriteLine("Presiona cualquier botón para continuar");
            Console.Read();
            Console.Clear();
            Console.WriteLine("Promedio de los sueldos es :"+promedio);
            Console.WriteLine("El total a pagar en planilla es :"+suma);
            Console.WriteLine("El mínimo de los sueldos es :"+ sueldoss[0]);
            Console.WriteLine("El máximo de los sueldos es:"+ sueldoss[cantidadE-1]);

            Console.Read();
        }
    }
}
