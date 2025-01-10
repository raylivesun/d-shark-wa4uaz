module console.dlang.lz1hm.sp9nsv.servers.np3cw;

import std.stdio;
import std.array;
import std.container;
import std.concurrency;
import std.digest;
import std.format;
import std.file;
import std.signals;
import std.path;
import std.getopt;
import std.logger;
import std.process;
import std.stdint;
import std.sumtype;
import std.numeric;
import std.uri;

void console()
{
    interface rota(dmd, gdc, ldc)
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
    write("PBar rota compiler");
}

