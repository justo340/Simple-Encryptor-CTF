main(void)

{
  int iVar1;
  time_t tVar2;
  long in_FS_OFFSET;
  uint seed;
  uint flag;
  long local_38;
  FILE *flag_file;
  size_t size_of_flag;
  void *local_20;
  FILE *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  flag_file = fopen("flag","rb");
  fseek(flag_file,0,2);
  size_of_flag = ftell(flag_file);
  fseek(flag_file,0,0);
  space_allocation= malloc(size_of_flag);
  fread(local_20,size_of_flag,1,flag_file);
  fclose(flag_file);
  tVar2 = time((time_t *)0x0);
  seed = (uint)tVar2;
  srand(seed);
  for (local_38 = 0; local_38 < (long)size_of_flag; local_38 = local_38 + 1) {
    iVar1 = rand();
    *(byte *)((long)space_allocation+ local_38) = *(byte *)((long)space_allocation+ local_38) ^ (byte)iVar1;
    flag = rand();
    flag = flag & 7;
    *(byte *)((long)space_allocation+ local_38) =
         *(byte *)((long)space_allocation+ local_38) << (sbyte)flag |
         *(byte *)((long)space_allocation+ local_38) >> 8 - (sbyte)flag;
  }
  local_18 = fopen("flag.enc","wb");
  fwrite(&seed,1,4,local_18);
  fwrite(local_20,1,size_of_flag,local_18);
  fclose(local_18);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}
