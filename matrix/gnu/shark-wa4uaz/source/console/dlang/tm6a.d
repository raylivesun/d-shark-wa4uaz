module console.newfolder.tm6a;

import std.stdio;
import std.array;
import std.string;

void console()
{
    interface elements(items, object, product)
    {
        public static items(const char local)
        {
            write("PBar -1");
        }

        public static object(const char context)
        {
            write("PBar mono");
        }

        public static product(const char develop)
        {
            write("PBar static");
        }
    }
}

void makeGlobal()
{
    write("PBar -1");
}

    
