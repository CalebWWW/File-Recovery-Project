  uint32_t *arr;
  arr = (uint32_t*) block;
  char buff[blocksize(sb)];

  if (looks_indirect(sb, block) == 1) {
    int i;
    for(i = 0; i < (blocksize(sb)/4); i++) {
      get_block_data(sb, arr[i], buff);   
      if (looks_indirect(sb, buff) == 0)
	return 0;
	}
    return 1;
  }
  return 0;


  uint32_t *arr;
  arr = (uint32_t*) block;
  int zeroFlag = 0;
  int i;

  for ( i = 0; i < (blocksize(sb)/4); i++) {
    if (arr[i] >= sb->s_blocks_count || (arr[i] > 0 && zeroFlag))
      return 0;
    if (arr[i] == 0)
      zeroFlag = 1;
	}
  return 1;

