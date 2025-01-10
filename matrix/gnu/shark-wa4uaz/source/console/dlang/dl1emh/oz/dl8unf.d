module console.dlang.dl1emh.newfolder.dl8unf;

import std.stdio;
import std.array;
import std.functional;
import std.encoding;
import std.container;
import std.bigint;
import std.format;
import std.meta;
import std.path;
import std.process;
import std.outbuffer;
import std.demangle;
import std.digest;
import std.concurrency;
import std.checkedint;
import std.int128;
import std.string;
import std.numeric;
import std.logger;
import std.uri;


void console()
{
    
    interface listOptionsCompiler(dmd, gdc, ldc)
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

void make()
{
    write("PBar --install compiler");
}
