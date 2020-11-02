using System;
using System.Runtime.CompilerServices;

public class Startup
{
    [MethodImpl(MethodImplOptions.InternalCall)]
    extern static void CPPFunc();

    public static void Main(string[] args)
    {
        Console.WriteLine("Hello from C#!");
        CPPFunc();
    }
}
