/* custom_linker.ld */
EXTERN(private_ioremap)
SECTIONS
{
    .text : {
        *(EXCLUDE_FILE(libfirmware.a:private_ioremap.o) .text)
    }
}
