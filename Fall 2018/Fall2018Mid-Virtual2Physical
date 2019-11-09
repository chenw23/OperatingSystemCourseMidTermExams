unsigned int directory[];   //which can be get from CR3 register

unsigned int computePhysicalAddress(unsigned int virtualAddress) {
    return ((void *) (directory[(virtualAddress & 0b11111111110000000000000000000000) >> 22])
    [(virtualAddress & 0b00000000001111111111000000000000) >> 12]) &
           0b11111111111111111111000000000000;
}


