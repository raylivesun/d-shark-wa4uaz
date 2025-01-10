module console.dlang.py4ars.e717mff;

import std.stdio;
import std.array;
import std.format;
import std.digest;
import std.file;
import std.getopt;
import std.encoding;
import std.getopt;
import std.string;
import std.bigint;

void console()
{
    interface wallet(dmd, gdc, ldc)
    {    
         public static dmd(const char compiler)
         {
             write("PBar dmd compiler");
         }
         public static gdc(const char compiler)
         {
             write("PBar gdc compiler");
         }
         public static ldc(const char compiler)
         {
             write("PBar ldc compiler");
         }
    }    
}

void makeGlobal()
{
    write("PBar wallet compiler");
}
