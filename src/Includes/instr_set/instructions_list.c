/* Copyright 2006-2019, BeatriX
 * File coded by BeatriX
 *
 * This file is part of BeaEngine.
 *
 *    BeaEngine is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    BeaEngine is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>. */


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aaa_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if ((*pMyDisasm).Archi == 64) GV.ERROR_OPCODE = UD_;
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aaa ");
  #endif
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
  (*pMyDisasm).Operand1.OpSize = 8;
  GV.EIP_++;
}

/* ====================================================================
 *  0f ff
 * ==================================================================== */
void __bea_callspec__ ud0_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ud0 ");
  #endif
  GvEv(pMyDisasm);
  GV.ERROR_OPCODE = UD_;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aad_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if ((*pMyDisasm).Archi == 64) GV.ERROR_OPCODE = UD_;
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aad ");
  #endif
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
  (*pMyDisasm).Operand1.OpSize = 16;
  if (!Security(1, pMyDisasm)) return;
  GV.ImmediatSize = 8;
  if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) != 0x0A) {
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));

    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
  }
  GV.EIP_+=2;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aam_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if ((*pMyDisasm).Archi == 64) GV.ERROR_OPCODE = UD_;

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aam ");
  #endif
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
  (*pMyDisasm).Operand1.OpSize = 16;
  if (!Security(1, pMyDisasm)) return;
  GV.ImmediatSize = 8;
  if (!Security(1, pMyDisasm)) return;
  if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) != 0x0A) {
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    if ((*pMyDisasm).Instruction.Immediat == 0) GV.ERROR_OPCODE = DE__;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
  }
  GV.EIP_+=2;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ aas_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if ((*pMyDisasm).Archi == 64) GV.ERROR_OPCODE = UD_;
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aas ");
  #endif
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
  (*pMyDisasm).Operand1.OpSize = 8;
  GV.EIP_++;
}

/* =======================================
 *      0Fh 38h F6h
 * large integer operation (adc and mul extensions)
 * ======================================= */
void __bea_callspec__ adcx_GyEy(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.EVEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
    if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
    if (GV.VEX.pp == 3) {
      (*pMyDisasm).Instruction.Category = BMI2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulx ");
      #endif
      if (GV.REX.W_ == 1) GV.OperandSize = 64;
      if (GV.OperandSize == 64) {
        GV.MemDecoration = Arg3qword;
      }
      else if (GV.OperandSize == 32) {
        GV.MemDecoration = Arg3dword;
      }
      else {
        GV.MemDecoration = Arg3word;
      }
      GyEy(pMyDisasm);
      (*pMyDisasm).Operand4.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand4.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand4.Registers.gpr = REGS[2];
      (*pMyDisasm).Operand4.OpSize = (GV.REX.W_ == 0) ? 32 : 64;
      (*pMyDisasm).Operand2.AccessMode = WRITE;
      FillFlags(pMyDisasm,125);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) GV.ERROR_OPCODE = UD_;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adox ");
      #endif
      if (GV.OperandSize != 64) GV.OperandSize = 32;
      GvEv(pMyDisasm);
      FillFlags(pMyDisasm,124);
    }
    /* ========= 0xf2 */
    else if (GV.PrefRepne == 1) {
      FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) GV.ERROR_OPCODE = UD_;

      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adcx ");
      #endif
      if (GV.OperandSize != 64) GV.OperandSize = 32;
      GvEv(pMyDisasm);
      FillFlags(pMyDisasm,123);
    }
    else {
      (*pMyDisasm).Instruction.Category = CET_INSTRUCTION;
      if ((GV.REX.state == InUsePrefix) && (GV.REX.W_ == 1)) {

        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "wrssq ");
        #endif
        GV.MemDecoration = Arg1qword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "wrssd ");
        #endif
        GV.MemDecoration = Arg1dword;
      }
      EvGv(pMyDisasm);
    }
  }
}

/* =======================================
 *      00h
 * ======================================= */
void __bea_callspec__ add_EbGb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
  #endif
  EbGb(pMyDisasm);
  FillFlags(pMyDisasm,5);
}

/* =======================================
 *      01h
 * ======================================= */
void __bea_callspec__ add_EvGv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
  #endif
  EvGv(pMyDisasm);
  FillFlags(pMyDisasm,5);
}

/* =======================================
 *      02h
 * ======================================= */
void __bea_callspec__ add_GbEb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
  #endif
  GbEb(pMyDisasm);
  FillFlags(pMyDisasm,5);
}

/* =======================================
 *      03h
 * ======================================= */
void __bea_callspec__ add_GvEv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
  #endif
  GvEv(pMyDisasm);
  FillFlags(pMyDisasm,5);
}

/* =======================================
 *      04h
 * ======================================= */
void __bea_callspec__ add_ALIb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
  #endif
  ALIb(pMyDisasm);
  FillFlags(pMyDisasm,5);
}

/* =======================================
 *      05h
 * ======================================= */
void __bea_callspec__ add_eAX_Iv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
  #endif
  eAX_Iv(pMyDisasm);
  FillFlags(pMyDisasm,5);
}

/* =======================================
 *      10h
 * ======================================= */
void __bea_callspec__ adc_EbGb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
  #endif
  EbGb(pMyDisasm);
  FillFlags(pMyDisasm,4);
}

/* =======================================
 *      11h
 * ======================================= */
void __bea_callspec__ adc_EvGv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
  #endif
  EvGv(pMyDisasm);
  FillFlags(pMyDisasm,4);
}

/* =======================================
 *      12h
 * ======================================= */
void __bea_callspec__ adc_GbEb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
  #endif
  GbEb(pMyDisasm);
  FillFlags(pMyDisasm,4);
}

/* =======================================
 *      13h
 * ======================================= */
void __bea_callspec__ adc_GvEv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
  #endif
  GvEv(pMyDisasm);
  FillFlags(pMyDisasm,4);
}

/* =======================================
 *      14h
 * ======================================= */
void __bea_callspec__ adc_ALIb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
  #endif
  ALIb(pMyDisasm);
  FillFlags(pMyDisasm,4);
}

/* =======================================
 *      15h
 * ======================================= */
void __bea_callspec__ adc_eAX_Iv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
  #endif
  eAX_Iv(pMyDisasm);
  FillFlags(pMyDisasm,4);
}

/* =======================================
 *      20h
 * ======================================= */
void __bea_callspec__ and_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      21h
 * ======================================= */
void __bea_callspec__ and_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      22h
 * ======================================= */
void __bea_callspec__ and_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      23h
 * ======================================= */
void __bea_callspec__ and_GvEv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
  #endif
  GvEv(pMyDisasm);
  FillFlags(pMyDisasm,6);
}

/* =======================================
 *      0fh 38h f2h
 * ======================================= */
void __bea_callspec__ andn_GyEy(PDISASM pMyDisasm)
{
  if ((GV.VEX.state == InUsePrefix) && (GV.EVEX.state != InUsePrefix)) {
    (*pMyDisasm).Instruction.Category = BMI1_INSTRUCTION + LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andn ");
    #endif
    GV.MemDecoration = (GV.REX.W_ == 0x1) ? Arg3qword : Arg3dword;
    GyEy(pMyDisasm);
    FillFlags(pMyDisasm,126);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      24h
 * ======================================= */
void __bea_callspec__ and_ALIb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
    (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
  #endif
  ALIb(pMyDisasm);
  FillFlags(pMyDisasm,6);
}

/* =======================================
 *      25h
 * ======================================= */
void __bea_callspec__ and_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ arpl_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsxd ");
        #endif
        GvEv(pMyDisasm);
        FillFlags(pMyDisasm,69);
    }
    else {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "arpl ");
        #endif
        GV.OperandSize = 16;
        EvGv(pMyDisasm);
        GV.OperandSize = 32;
        FillFlags(pMyDisasm,7);
    }

}

/* =======================================
 *      0f 38 f7
 * ======================================= */
void __bea_callspec__ bextr_GyEy(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 0) {
      (*pMyDisasm).Instruction.Category = BMI1_INSTRUCTION + LOGICAL_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bextr ");
      #endif
    }
    else if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = BMI2_INSTRUCTION + LOGICAL_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shlx ");
      #endif
    }
    else if (GV.VEX.pp == 2) {
      (*pMyDisasm).Instruction.Category = BMI2_INSTRUCTION + LOGICAL_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sarx ");
      #endif
    }
    else {
      (*pMyDisasm).Instruction.Category = BMI2_INSTRUCTION + LOGICAL_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shrx ");
      #endif
    }

    GV.MemDecoration = (GV.REX.W_ == 0x1) ? Arg2qword : Arg2dword;
    GV.OperandSize = (GV.REX.W_ == 1) ? 64 : 32;
    Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
    MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
    GV.OperandSize = 8;
    fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand3, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,127);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* =======================================
 *      62h
 * ======================================= */
void __bea_callspec__ bound_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {

      /* EVEX 4Bytes prefix */

      if (!Security(4, pMyDisasm)) return;
      GV.EVEX.P0 = *((UInt8*)(UIntPtr) (GV.EIP_+1));
      GV.EVEX.P1 = *((UInt8*)(UIntPtr) (GV.EIP_+2));
      GV.EVEX.P2 = *((UInt8*)(UIntPtr) (GV.EIP_+3));

      /* P[3:2] must be zero */
      if (((GV.EVEX.P0 >> 2) & 0x3) != 0) {
        FailDecode(pMyDisasm);
      }
      /* P[10] must be 1 */
      if (((GV.EVEX.P1 >> 2) & 0x1) != 1) {
        FailDecode(pMyDisasm);
      }

      GV.EVEX.state = InUsePrefix;
      GV.EVEX.mm = GV.EVEX.P0 & 0x3;           /* P[1:0] */
      GV.EVEX.pp = GV.EVEX.P1 & 0x3;           /* P[9:8] */
      GV.EVEX.R1 = ~(GV.EVEX.P0 >> 4) & 0x1;      /* P[4] */
      GV.EVEX.X = ~(GV.EVEX.P0 >> 6) & 0x1;      /* P[6] */
      GV.EVEX.B = ~(GV.EVEX.P0 >> 5) & 0x1;      /* P[5] */
      GV.EVEX.R = ~(GV.EVEX.P0 >> 7) & 0x1;      /* P[5] */
      GV.EVEX.vvvv = (GV.EVEX.P1 >> 3) & 0xF; /* P[14:11] */
      GV.EVEX.V = ~(GV.EVEX.P2 >> 3) & 0x1;      /* P[19] */
      GV.EVEX.aaa = (GV.EVEX.P2) & 0x7;       /* P[18:16] */
      GV.EVEX.W = (GV.EVEX.P1 >> 7) & 0x1;      /* P[15] */
      GV.EVEX.z = (GV.EVEX.P2 >> 7) & 0x1;      /* P[23] */
      GV.EVEX.b = (GV.EVEX.P2 >> 4) & 0x1;      /* P[20] */
      GV.EVEX.LL = (GV.EVEX.P2 >> 5) & 0x3;    /*  P[22:21]*/

      /* Use VEX to implement EVEX basic functionalities */
      GV.VEX.state = InUsePrefix;
      GV.VEX.mmmmm = GV.EVEX.mm;
      GV.VEX.pp = GV.EVEX.pp;
      GV.VEX.vvvv = GV.EVEX.vvvv;
      GV.VEX.L = GV.EVEX.LL;  /* Thus, VEX.L can have 0x2 value */
      GV.REX.X_ = GV.EVEX.X;
      GV.REX.R_ = GV.EVEX.R;
      GV.REX.B_ = GV.EVEX.B;

      if (GV.EVEX.pp == 0x0) {
          GV.NB_PREFIX++;
          (*pMyDisasm).Prefix.Number++;
          GV.EIP_+=4;
          (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
          if (GV.EVEX.mm == 0x1) {
            (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else if (GV.EVEX.mm == 0x2) {
            (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else if (GV.EVEX.mm == 0x3) {
            (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else {
            FailDecode(pMyDisasm);
          }
      }
      if (GV.EVEX.pp == 0x1) {
        /* 66h */
        GV.EIP_+=3;
        (*pMyDisasm).Prefix.OperandSize = InUsePrefix;
        GV.EIP_++;
        (*pMyDisasm).Prefix.Number++;
        GV.NB_PREFIX++;
        GV.OriginalOperandSize = GV.OperandSize;  /* if GV.OperandSize is used as a mandatory prefix, keep the real operandsize value */
        if (GV.Architecture == 16) {
          GV.OperandSize = 32;
        }
        else {
          if (GV.OperandSize != 64) {
            GV.OperandSize = 16;
          }
        }
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        if (GV.VEX.mmmmm == 0x1) {
          (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x2) {
          (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x3) {
          (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else {
          GV.ERROR_OPCODE = UD_;
          FailDecode(pMyDisasm);
        }
        GV.OperandSize = (GV.Architecture == 16) ? 16 : 32;
      }
      else if (GV.EVEX.pp == 0x2) {
        /* F3h */
        GV.EIP_+=3;
        (*pMyDisasm).Prefix.RepPrefix = SuperfluousPrefix;
        GV.EIP_++;
        (*pMyDisasm).Prefix.Number++;
        GV.NB_PREFIX++;
        GV.PrefRepe = 1;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        if (GV.VEX.mmmmm == 0x1) {
            (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x2) {
            (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x3) {
            (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else {
            GV.ERROR_OPCODE = UD_;
            FailDecode(pMyDisasm);
        }
        GV.PrefRepe = 0;
      }
      else if (GV.EVEX.pp == 0x3) {
        /* F2h */
        GV.EIP_+=3;
        (*pMyDisasm).Prefix.RepnePrefix = SuperfluousPrefix;
        GV.EIP_++;
        (*pMyDisasm).Prefix.Number++;
        GV.NB_PREFIX++;
        GV.PrefRepne = 1;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        if (GV.VEX.mmmmm == 0x1) {
            (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x2) {
            (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x3) {
            (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else {
            GV.ERROR_OPCODE = UD_;
            FailDecode(pMyDisasm);
        }
        GV.PrefRepne = 0;
      }
      GV.OperandSize = 32;
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bound ");
      #endif
      GvEv(pMyDisasm);
      GV.MemDecoration = Arg2dword;
      (*pMyDisasm).Operand1.AccessMode = READ;
      FillFlags(pMyDisasm,8);
    }

}

/* =======================================
 *      0fh 1ah
 * ======================================= */
void __bea_callspec__ bndcl_GvEv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.PrefRepe == 1) {
    (*pMyDisasm).Instruction.Category = MPX_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bndcl ");
    #endif
    GV.Register_ = MPX_REG;
    GvEv(pMyDisasm);

    (*pMyDisasm).Operand1.AccessMode = READ;
  }
  /* ========= 0xf2 */
  else if (GV.PrefRepne == 1) {
    (*pMyDisasm).Instruction.Category = MPX_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bndcu ");
    #endif
    GV.Register_ = MPX_REG;
    GvEv(pMyDisasm);

    (*pMyDisasm).Operand1.AccessMode = READ;
  }
  /* ========= 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    (*pMyDisasm).Instruction.Category = MPX_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bndmov ");
    #endif
    GV.Register_ = MPX_REG;
    GvEv(pMyDisasm);

    if (GV.MOD_ != 3) {
      if (GV.Architecture == 64) {
          GV.MemDecoration = Arg2dqword;
      }
      else {
          GV.MemDecoration = Arg2qword;
      }
    }

  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* =======================================
 *      0fh 1bh
 * ======================================= */
void __bea_callspec__ bndcn_GvEv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Instruction.Category = MPX_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bndmk ");
        #endif
        GV.Register_ = MPX_REG;
        GvEv(pMyDisasm);

        (*pMyDisasm).Operand1.AccessMode = READ;

    }
    /* ========= 0xf2 */
    else if (GV.PrefRepne == 1) {
        (*pMyDisasm).Instruction.Category = MPX_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bndcn ");
        #endif
        GV.Register_ = MPX_REG;
        GvEv(pMyDisasm);

        (*pMyDisasm).Operand1.AccessMode = READ;
    }
    /* ========= 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = MPX_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bndmov ");
        #endif
        GV.Register_ = MPX_REG;
        EvGv(pMyDisasm);

        if (GV.MOD_ != 3) {
            if (GV.Architecture == 64) {
                GV.MemDecoration = Arg1dqword;
            }
            else {
                GV.MemDecoration = Arg1qword;
            }
        }

    }
    else {
        (*pMyDisasm).Instruction.Category = MPX_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bndstx ");
        #endif
        GV.Register_ = MPX_REG;
        EvGv(pMyDisasm);

    }

}

void __bea_callspec__ bswap_args(PDISASM pMyDisasm, int index)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
  #endif
  if (GV.OperandSize == 64) {
    (*pMyDisasm).Operand1.OpSize = 64;
    if (GV.REX.B_ == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[index+8]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+8];
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[index+0]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+0];
    }
  }
  else if (GV.OperandSize == 32){
    (*pMyDisasm).Operand1.OpSize = 32;
    if (GV.REX.B_ == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[index+8]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+8];
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[index+0]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+0];
    }
  }
  else {
    (*pMyDisasm).Operand1.OpSize = 16;
    if (GV.REX.B_ == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[index+8]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+8];
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[index+0]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+0];
    }
  }
  GV.EIP_++;
  FillFlags(pMyDisasm,10);
}
/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_eax(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 0);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ecx(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 1);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edx(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 2);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebx(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 3);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esp(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 4);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebp(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 5);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esi(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 6);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edi(PDISASM pMyDisasm)
{
  bswap_args(pMyDisasm, 7);
}

/* =======================================
 *      0fbch
 * ======================================= */
void __bea_callspec__ bsf_GvEv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsf ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,9);
  }
}

/* =======================================
 *      0fbdh
 * ======================================= */
void __bea_callspec__ bsr_GvEv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsr ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,9);
  }
}

/* =======================================
 *      0fbbh
 * ======================================= */
void __bea_callspec__ btc_EvGv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btc ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,11);
  }
}

/* =======================================
 *      0fa3h
 * ======================================= */
void __bea_callspec__ bt_EvGv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bt ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,11);
  }
}

/* =======================================
 *      0fb3h
 * ======================================= */
void __bea_callspec__ btr_EvGv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btr ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,11);
  }
}

/* =======================================
 *      0fabh
 * ======================================= */
void __bea_callspec__ bts_EvGv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bts ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,11);
  }
}


/* =======================================
 *      0fh 38h f5h
 * ======================================= */
void __bea_callspec__ bzhi_GyEy(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.EVEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
    if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
    if (GV.VEX.pp == 0) {
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + LOGICAL_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bzhi ");
      #endif
      GV.MemDecoration = (GV.REX.W_ == 0x1) ? Arg2qword : Arg2dword;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.OperandSize = 8;
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      FillFlags(pMyDisasm,128);
    }
    else if (GV.VEX.pp == 3) {
      (*pMyDisasm).Instruction.Category = BMI2_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pdep ");
      #endif
      GV.MemDecoration = (GV.REX.W_ == 0x1) ? Arg3qword : Arg3dword;
      GyEy(pMyDisasm);
    }
    else if (GV.VEX.pp == 2) {
      (*pMyDisasm).Instruction.Category = BMI2_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pext ");
      #endif
      GV.MemDecoration = (GV.REX.W_ == 0x1) ? Arg3qword : Arg3dword;
      GyEy(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = CET_INSTRUCTION;
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;

      if (GV.REX.W_ == 1) {
        GV.MemDecoration = Arg1qword;
        GV.OperandSize = 64;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "wrussq ");
        #endif
      }
      else {
        GV.MemDecoration = Arg1dword;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "wrussd ");
        #endif
      }
      EvGv(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}

/* =======================================
 *      e8h
 * ======================================= */
void __bea_callspec__ call_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = CallType;

    (*pMyDisasm).Operand1.AccessMode = READ;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        (*pMyDisasm).Operand1.OpSize = 32;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1))+5+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        if (MyAddress >= 0x80000000) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        (*pMyDisasm).Operand1.OpSize = 32;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1))+3+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ callf_(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    UInt64 MyAddress;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = CallType;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lcall ");
            #endif
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic,"\x24");
            #endif
            i++;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call far ");
            #endif
        }
        if (GV.OperandSize ==32) {
            if (!Security(7, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+5));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        else {
            if (!Security(5, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+3));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic+i, " , \x24");
            #endif
            i+=4;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic+i, " : ");
            #endif
            i+=3;
        }
        MyAddress = MyNumber*16;
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic+i, "%.8X",(Int64) MyNumber);
        #endif
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
    }
}

/* =======================================
 *      99h
 * ======================================= */
void __bea_callspec__ cdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG2;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
    if (GV.OperandSize == 64) {
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cqto ");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cqo ");
            #endif
        }
        (*pMyDisasm).Operand1.OpSize = 64;
    }
    else if (GV.OperandSize ==32) {
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cltd ");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdq ");
            #endif
        }
        (*pMyDisasm).Operand1.OpSize = 32;
    }
    else {
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwtd ");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwd ");
            #endif
        }
        (*pMyDisasm).Operand1.OpSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ clts_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clts ");
  #endif
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = CR_REG;
  (*pMyDisasm).Operand1.Registers.cr = REG0;
  (*pMyDisasm).Operand1.OpSize = 1;
  FillFlags(pMyDisasm, 17);
  GV.EIP_++;
}


/* =======================================
 *      F5h
 * ======================================= */
void __bea_callspec__ cmc_(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmc ");
  #endif
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand1.Registers.special = REG0;
  (*pMyDisasm).Operand1.OpSize = 1;
  FillFlags(pMyDisasm, 18);
  GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovo_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovo ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ getsec_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    if (
      ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) ||
      ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) ||
      ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) ||
      ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix)
    ) {
      GV.ERROR_OPCODE = UD_;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "getsec ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand1.OpSize = 64;
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnb_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnb ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovns_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovns ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovl_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovl ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnl_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnl ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovle_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovle ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnle_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnle ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmpx_EbGb(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg ");
  #endif
  EbGb(pMyDisasm);
  FillFlags(pMyDisasm,22);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmpx_EvGv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg ");
  #endif
  EvGv(pMyDisasm);
  FillFlags(pMyDisasm,22);
}

/* =======================================
 *      38h
 * ======================================= */
void __bea_callspec__ cmp_EbGb(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
  #endif
  EbGb(pMyDisasm);
  (*pMyDisasm).Operand1.AccessMode = READ;
  FillFlags(pMyDisasm,20);
}

/* =======================================
 *      39h
 * ======================================= */
void __bea_callspec__ cmp_EvGv(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
  #endif
  EvGv(pMyDisasm);
  (*pMyDisasm).Operand1.AccessMode = READ;
  FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3ah
 * ======================================= */
void __bea_callspec__ cmp_GbEb(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
  #endif
  GbEb(pMyDisasm);
  (*pMyDisasm).Operand1.AccessMode = READ;
  FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3bh
 * ======================================= */
void __bea_callspec__ cmp_GvEv(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
  #endif
  GvEv(pMyDisasm);
  (*pMyDisasm).Operand1.AccessMode = READ;
  FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3ch
 * ======================================= */
void __bea_callspec__ cmp_ALIb(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
  #endif
  ALIb(pMyDisasm);
  (*pMyDisasm).Operand1.AccessMode = READ;
  FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3dh
 * ======================================= */
void __bea_callspec__ cmp_eAX_Iv(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
  #endif
  eAX_Iv(pMyDisasm);
  (*pMyDisasm).Operand1.AccessMode = READ;
  FillFlags(pMyDisasm,20);
}

/* =======================================
 *      a6h
 * ======================================= */
void __bea_callspec__ cmpsb_(PDISASM pMyDisasm)
{
  /* ========= 0xf3 */
  if (GV.PrefRepe == 1) {
      (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
  }
  /* ========= 0xf2 */
  if (GV.PrefRepne == 1) {
      (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsb ");
  #endif
  (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
  (*pMyDisasm).Operand1.OpSize = 8;
  (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
  (*pMyDisasm).Operand1.AccessMode = READ;
  (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
  (*pMyDisasm).Operand2.OpSize = 8;
  (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
  FillFlags(pMyDisasm,21);
  GV.EIP_++;
}

/* =======================================
 *      a7h
 * ======================================= */
void __bea_callspec__ cmps_(PDISASM pMyDisasm)
{
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
    if (GV.Architecture == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsq ");
        #endif
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsd ");
        #endif
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsw ");
        #endif
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
    FillFlags(pMyDisasm,21);
    GV.EIP_++;
}

/* =======================================
 *      98h
 * ======================================= */
void __bea_callspec__ cwde_(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
  if (GV.OperandSize == 64) {
      if (GV.SYNTAX_ == ATSyntax) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cltq ");
          #endif
      }
      else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdqe ");
          #endif
      }
      (*pMyDisasm).Operand1.OpSize = 64;
  }
  else if (GV.OperandSize == 32) {
      if (GV.SYNTAX_ == ATSyntax) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwtl ");
          #endif
      }
      else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwde ");
          #endif
      }
      (*pMyDisasm).Operand1.OpSize = 32;
  }
  else {
      if (GV.SYNTAX_ == ATSyntax) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cbtw ");
          #endif
      }
      else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cbw ");
          #endif
      }
      (*pMyDisasm).Operand1.OpSize = 16;
  }
  GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ clc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
    (*pMyDisasm).Operand1.Registers.special = REG0;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clc ");
    #endif
    (*pMyDisasm).Operand1.OpSize = 1;
    FillFlags(pMyDisasm, 14);
    GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ cld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
    (*pMyDisasm).Operand1.Registers.special = REG0;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cld ");
    #endif
    (*pMyDisasm).Operand1.OpSize = 1;
    FillFlags(pMyDisasm, 15);
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cli_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
    (*pMyDisasm).Operand1.Registers.special = REG0;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cli ");
    #endif
    (*pMyDisasm).Operand1.OpSize = 1;
    FillFlags(pMyDisasm, 16);
    GV.EIP_++;
}

/* =======================================
 *      0fa2h
 * ======================================= */
void __bea_callspec__ cpuid_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand1.Registers.gpr = REG0+REG1+REG2+REG3;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cpuid ");
    #endif
    (*pMyDisasm).Operand1.OpSize = 32;
    GV.EIP_++;
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ daa_(PDISASM pMyDisasm)
{
  if (GV.Architecture == 64) {
      FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "daa ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand1.OpSize = 8;
    FillFlags(pMyDisasm,28);
    GV.EIP_++;
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ das_(PDISASM pMyDisasm)
{

  if (GV.Architecture == 64) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "das ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand1.OpSize = 8;
    FillFlags(pMyDisasm,29);
    GV.EIP_++;
  }

}

void __bea_callspec__ dec_args(PDISASM pMyDisasm, int index)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
    GV.ERROR_OPCODE = UD_;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
  #endif
  if (GV.OperandSize == 32) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[index+0]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+0];
      (*pMyDisasm).Operand1.OpSize = 32;
  }
  else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[index+0]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[index+0];
      (*pMyDisasm).Operand1.OpSize = 16;
  }
  GV.EIP_++;
  FillFlags(pMyDisasm, 30);
}

/* =======================================
 *      48h
 * ======================================= */
void __bea_callspec__ dec_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;
    }
    else {
      dec_args(pMyDisasm, 0);
    }
}

/* =======================================
 *      49h
 * ======================================= */
void __bea_callspec__ dec_ecx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
      dec_args(pMyDisasm, 1);
    }
}

/* =======================================
 *      4ah
 * ======================================= */
void __bea_callspec__ dec_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
      dec_args(pMyDisasm, 2);
    }
}

/* =======================================
 *      4bh
 * ======================================= */
void __bea_callspec__ dec_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
      dec_args(pMyDisasm, 3);
    }
}

/* =======================================
 *      4ch
 * ======================================= */
void __bea_callspec__ dec_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
      dec_args(pMyDisasm, 4);
    }
}

/* =======================================
 *      4dh
 * ======================================= */
void __bea_callspec__ dec_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
      dec_args(pMyDisasm, 5);
    }
}

/* =======================================
 *      4eh
 * ======================================= */
void __bea_callspec__ dec_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
      dec_args(pMyDisasm, 6);
    }
}

/* =======================================
 *      4fh
 * ======================================= */
void __bea_callspec__ dec_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
      dec_args(pMyDisasm, 7);
    }
}

/* =======================================
 *      0c8h
 * ======================================= */
void __bea_callspec__ enter_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "enter ");
    #endif
    if (!Security(3, pMyDisasm)) return;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic,"%.4X",(Int64) *((UInt16*)(UIntPtr) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+ABSOLUTE_;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+3)));
    #endif
    (*pMyDisasm).Operand2.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    GV.EIP_+=4;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ femms_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = AMD_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "femms ");
  #endif
  GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ hlt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hlt ");
    #endif
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ invd_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "invd ");
  #endif
  GV.EIP_++;
}

/* =======================================
 *      40h
 * ======================================= */
void __bea_callspec__ inc_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        if (GV.REX.W_ == 1) GV.OperandSize = 32;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;
    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      41h
 * ======================================= */
void __bea_callspec__ inc_ecx(PDISASM pMyDisasm)
{
  if (GV.Architecture == 64) {
    if (!Security(1, pMyDisasm)) return;
    if (GV.REX.W_ == 1) GV.OperandSize = 32;
    GV.REX.W_ = 0;
    GV.REX.R_ = 0;
    GV.REX.X_ = 0;
    GV.REX.B_ = 1;
    GV.REX.state = InUsePrefix;
    GV.EIP_++;
    GV.NB_PREFIX++;
    (*pMyDisasm).Prefix.Number++;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
    GV.OperandSize = 32;
  }
  else {
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
      GV.ERROR_OPCODE = UD_;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
    #endif
    if (GV.OperandSize == 32) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[1]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[1+0];
      (*pMyDisasm).Operand1.OpSize = 32;
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[1]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
      (*pMyDisasm).Operand1.Registers.gpr = REGS[1+0];
      (*pMyDisasm).Operand1.OpSize = 16;
    }
    GV.EIP_++;
    FillFlags(pMyDisasm, 40);
  }
}

/* =======================================
 *      42h
 * ======================================= */
void __bea_callspec__ inc_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        if (GV.REX.W_ == 1) GV.OperandSize = 32;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[2]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[2+0];
            (*pMyDisasm).Operand1.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[2]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[2+0];
            (*pMyDisasm).Operand1.OpSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      43h
 * ======================================= */
void __bea_callspec__ inc_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        if (GV.REX.W_ == 1) GV.OperandSize = 32;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[3]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[3+0];
            (*pMyDisasm).Operand1.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[3]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[3+0];
            (*pMyDisasm).Operand1.OpSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      44h
 * ======================================= */
void __bea_callspec__ inc_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        if (GV.REX.W_ == 1) GV.OperandSize = 32;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[4]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[4+0];
            (*pMyDisasm).Operand1.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[4]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[4+0];
            (*pMyDisasm).Operand1.OpSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      45h
 * ======================================= */
void __bea_callspec__ inc_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        if (GV.REX.W_ == 1) GV.OperandSize = 32;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[5]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[5+0];
            (*pMyDisasm).Operand1.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[5]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[5+0];
            (*pMyDisasm).Operand1.OpSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      46h
 * ======================================= */
void __bea_callspec__ inc_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        if (GV.REX.W_ == 1) GV.OperandSize = 32;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[6]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[6+0];
            (*pMyDisasm).Operand1.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[6]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[6+0];
            (*pMyDisasm).Operand1.OpSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      47h
 * ======================================= */
void __bea_callspec__ inc_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(1, pMyDisasm)) return;
        if (GV.REX.W_ == 1) GV.OperandSize = 32;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[7]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[7+0];
            (*pMyDisasm).Operand1.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[7]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[7+0];
            (*pMyDisasm).Operand1.OpSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }

}
/* =======================================
 *  0xcf
 * ======================================= */
void __bea_callspec__ iret_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    if (GV.OperandSize ==64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretq ");
        #endif
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretd ");
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretw ");
        #endif
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ in_ALDX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers8Bits[0]);
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[2]);
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand1.Registers.gpr = REGS[0];
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand2.Registers.gpr = REGS[2];
    (*pMyDisasm).Operand2.OpSize = 16;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ in_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    ALIb(pMyDisasm);
}

/* =======================================
 *      0xe5
 * ======================================= */
void __bea_callspec__ in_eAX_Ib(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand1.Registers.gpr = REGS[0];
    (*pMyDisasm).Operand1.OpSize = 32;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_+=2;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ insb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insb ");
    #endif
    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG2;
    (*pMyDisasm).Operand2.OpSize = 16;
    GV.EIP_++;
    FillFlags(pMyDisasm, 41);


}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ ins_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    if (GV.OperandSize >= 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insd ");
        #endif
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG2;
        (*pMyDisasm).Operand2.OpSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, 41);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insw ");
        #endif
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG2;
        (*pMyDisasm).Operand2.OpSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, 41);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ into_(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "into ");
        #endif
        GV.EIP_++;
        FillFlags(pMyDisasm, 43);
    }
}

/* =======================================
 *      0edh
 * ======================================= */
void __bea_callspec__ in_eAX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    if (GV.OperandSize >=32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[2]);
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REGS[0];
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REGS[2];
        (*pMyDisasm).Operand2.OpSize = 16;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[2]);
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REGS[0];
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REGS[2];
        (*pMyDisasm).Operand2.OpSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *      0cdh
 * ======================================= */
void __bea_callspec__ int_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand1.OpSize = 8;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      0f1h
 * ======================================= */
void __bea_callspec__ int1_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int1 ");
    #endif
    GV.EIP_++;
    FillFlags(pMyDisasm, 42);
  }
}

/* =======================================
 *      0cch
 * ======================================= */
void __bea_callspec__ int3_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int3 ");
    #endif
    GV.EIP_++;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      69h
 * ======================================= */
void __bea_callspec__ imul_GvEvIv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    #endif
    if (GV.OperandSize >= 32) {
      GV.MemDecoration = (GV.OperandSize == 64) ? Arg2qword : Arg2dword;
      GV.ImmediatSize = 32;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

      GV.EIP_+= GV.DECALAGE_EIP+2;
      if (!Security(3, pMyDisasm)) return;
      (*pMyDisasm).Instruction.Immediat = *((UInt32*)(UIntPtr) (GV.EIP_- 0));
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand3.OpMnemonic, "%.8X",(Int64) *((UInt32*)(UIntPtr) (GV.EIP_- 0)));
      #endif
      GV.EIP_+=4;
      (*pMyDisasm).Operand3.OpType = CONSTANT_TYPE+ABSOLUTE_;
      (*pMyDisasm).Operand3.OpSize = 32;

      FillFlags(pMyDisasm, 38);
    }
    else {
      GV.MemDecoration = Arg2word;
      GV.ImmediatSize = 16;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_+= GV.DECALAGE_EIP+2;
      if (!Security(1, pMyDisasm)) return;
      (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_- 0));
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand3.OpMnemonic, "%.4X",(Int64) *((UInt16*)(UIntPtr) (GV.EIP_- 0)));
      #endif
      GV.EIP_+=2;
      (*pMyDisasm).Operand3.OpType = CONSTANT_TYPE+ABSOLUTE_;
      (*pMyDisasm).Operand3.OpSize = 16;

      FillFlags(pMyDisasm, 38);
    }
}

/* =======================================
 *      6bh
 * ======================================= */
void __bea_callspec__ imul_GvEvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 0));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand3.OpMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 0)));
        #endif
        GV.EIP_+= 1;
        (*pMyDisasm).Operand3.OpType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Operand3.OpSize = 8;

        FillFlags(pMyDisasm, 38);
    }
    else {
        GV.MemDecoration = Arg2word;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

        GV.EIP_+= GV.DECALAGE_EIP+2;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 0));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand3.OpMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 0)));
        #endif
        GV.EIP_+=1;
        (*pMyDisasm).Operand3.OpType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Operand3.OpSize = 8;
        FillFlags(pMyDisasm, 38);
    }
}

/* =======================================
 *      0fafh
 * ======================================= */
void __bea_callspec__ imul_GvEv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,38);
  }
}

/* =======================================
 *      7xh
 * ======================================= */
void __bea_callspec__ jcc_short(PDISASM pMyDisasm, const char* mnemonic, int flags, int branch_type)
{
  UInt64 MyAddress;

  signed long MyNumber;
  if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
      (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
      (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
  }
  if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
      (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
      (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
  (*pMyDisasm).Instruction.BranchType = branch_type;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic);
  #endif
  if (!Security(1, pMyDisasm)) return;
  MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
  CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
  if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
  if (MyAddress >= W64LIT (0x100000000)) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
      #endif
  }
  else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
      #endif
  }
  (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
  (*pMyDisasm).Operand1.OpSize = 8;
  (*pMyDisasm).Operand1.AccessMode = READ;
  (*pMyDisasm).Instruction.AddrValue = MyAddress;
  GV.EIP_+=2;
  FillFlags(pMyDisasm, flags);
}
/* =======================================
 *      70h
 * ======================================= */
void __bea_callspec__ jo_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jo ", 116, JO);
}

/* =======================================
 *      71h
 * ======================================= */
void __bea_callspec__ jno_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jno ", 116, JNO);
}

/* =======================================
 *      72h
 * ======================================= */
void __bea_callspec__ jc_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jc ", 117, JC);
}

/* =======================================
 *      73h
 * ======================================= */
void __bea_callspec__ jnc_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jnc ", 117, JNC);
}
/* =======================================
 *      74h
 * ======================================= */
void __bea_callspec__ je_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "je ", 118, JE);
}

/* =======================================
 *      75h
 * ======================================= */
void __bea_callspec__ jne_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jne ", 49, JNE);
}

/* =======================================
 *      76h
 * ======================================= */
void __bea_callspec__ jbe_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jbe ", 119, JNA);
}

/* =======================================
 *      77h
 * ======================================= */
void __bea_callspec__ jnbe_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jnbe ", 119, JA);
}

/* =======================================
 *      78h
 * ======================================= */
void __bea_callspec__ js_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "js ", 120, JS);
}

/* =======================================
 *      79h
 * ======================================= */
void __bea_callspec__ jns_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jns ", 120, JNS);
}

/* =======================================
 *      7ah
 * ======================================= */
void __bea_callspec__ jp_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jp ", 121, JP);
}

/* =======================================
 *      7bh
 * ======================================= */
void __bea_callspec__ jnp_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jnp ", 121, JNP);
}

/* =======================================
 *      7ch
 * ======================================= */
void __bea_callspec__ jl_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jl ", 122, JL);
}

/* =======================================
 *      7dh
 * ======================================= */
void __bea_callspec__ jnl_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jnl ", 122, JNL);
}

/* =======================================
 *      7eh
 * ======================================= */
void __bea_callspec__ jle_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jle ", 115, JNG);
}

/* =======================================
 *      7fh
 * ======================================= */
void __bea_callspec__ jnle_(PDISASM pMyDisasm)
{
  jcc_short(pMyDisasm, "jnle ", 115, JG);
}

/* =======================================
 *      0f 8xh
 * ======================================= */
void __bea_callspec__ jcc_near(PDISASM pMyDisasm, const char* mnemonic, int flags, int branch_type)
{
  UInt64 MyAddress;
  long MyNumber;
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
      (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
      (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
  }
  if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
      (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
      (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
  (*pMyDisasm).Instruction.BranchType = branch_type;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic);
  #endif
  if (GV.OperandSize >= 32) {
      if (!Security(4, pMyDisasm)) return;
      MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
      CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
      if (MyAddress >= W64LIT (0x100000000)) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
          #endif
      }
      else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
          #endif
      }
      (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
      (*pMyDisasm).Operand1.OpSize = 32;
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Instruction.AddrValue = MyAddress;
      GV.EIP_+=5;
      FillFlags(pMyDisasm,flags);
  }
  else {
      if (!Security(2, pMyDisasm)) return;
      MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
      CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
      MyAddress = MyAddress & 0xffff;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
      #endif
      (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
      (*pMyDisasm).Operand1.OpSize = 16;
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Instruction.AddrValue = MyAddress;
      GV.EIP_+=3;
      FillFlags(pMyDisasm, flags);
  }
}
/* =======================================
 *      0f80h
 * ======================================= */
void __bea_callspec__ jo_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jo ", 116, JO);
}


/* =======================================
 *      0f81h
 * ======================================= */
void __bea_callspec__ jno_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jno ", 116, JNO);
}

/* =======================================
 *      0f82h
 * ======================================= */
void __bea_callspec__ jc_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jc ", 117, JC);
}

/* =======================================
 *      0f83h
 * ======================================= */
void __bea_callspec__ jnc_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jnc ", 117, JNC);
}

/* =======================================
 *      0f84h
 * ======================================= */
void __bea_callspec__ je_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "je ", 118, JE);
}

/* =======================================
 *      0f85h
 * ======================================= */
void __bea_callspec__ jne_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jne ", 118, JNE);
}
/* =======================================
 *      0f86h
 * ======================================= */
void __bea_callspec__ jbe_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jbe ", 49, JNA);
}


/* =======================================
 *      0f87h
 * ======================================= */
void __bea_callspec__ ja_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "ja ", 119, JA);
}

/* =======================================
 *      0f88h
 * ======================================= */
void __bea_callspec__ js_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "js ", 120, JS);
}

/* =======================================
 *      0f89h
 * ======================================= */
void __bea_callspec__ jns_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jns ", 120, JNS);
}

/* =======================================
 *      0f8ah
 * ======================================= */
void __bea_callspec__ jp_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jp ", 121, JP);
}

/* =======================================
 *      0f8bh
 * ======================================= */
void __bea_callspec__ jnp_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jnp ", 121, JNP);
}

/* =======================================
 *      0f8ch
 * ======================================= */
void __bea_callspec__ jl_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jl ", 122, JL);
}

/* =======================================
 *      0f8dh
 * ======================================= */
void __bea_callspec__ jnl_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jl ", 122, JNL);
}

/* =======================================
 *      0f8eh
 * ======================================= */
void __bea_callspec__ jle_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jng ", 115, JNG);
}

/* =======================================
 *      0f8fh
 * ======================================= */
void __bea_callspec__ jnle_near(PDISASM pMyDisasm)
{
  jcc_near(pMyDisasm, "jg ", 115, JG);
}

/* =======================================
 *      0e3h
 * ======================================= */
void __bea_callspec__ jecxz_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int64 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JECXZ;
    (*pMyDisasm).Operand1.OpSize = 8;
    if (GV.AddressSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jrcxz ");
        #endif
    }
    else if (GV.AddressSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jecxz ");
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jcxz ");
        #endif
    }
    if (GV.OperandSize >= 32) {
        if (!Security(1, pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(1, pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0e9h
 * ======================================= */
void __bea_callspec__ jmp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Operand1.AccessMode = READ;

    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        (*pMyDisasm).Operand1.OpSize = 32;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+5+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;

        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,51);
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        (*pMyDisasm).Operand1.OpSize = 16;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+3+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,51);
    }
}


/* =======================================
 *      0ebh
 * ======================================= */
void __bea_callspec__ jmp_short(PDISASM pMyDisasm)
{
    UInt64 MyAddress = 0;
    signed long MyNumber = 0;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Operand1.OpSize = 8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ jmp_far(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    UInt64 MyAddress;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = JmpType;
        (*pMyDisasm).Operand1.AccessMode = READ;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ljmp ");
            #endif
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic,"\x24");
            #endif
            i++;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp far ");
            #endif
        }
        if (GV.OperandSize ==32) {
            if (!Security(6, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+5));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        else {
            if (!Security(4, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+3));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic+i, " , \x24");
            #endif
            i+=4;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic+i, " : ");
            #endif
            i+=3;
        }
        MyAddress = MyNumber*16;
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic+i, "%.8X",(Int64) MyNumber);
        #endif
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
        FillFlags(pMyDisasm,51);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lahf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lahf ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand2.Registers.special = REG0;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lar_GvEw(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lar ");
    #endif
    GvEv(pMyDisasm);
    if (GV.MOD_ != 0x3) {
      GV.MemDecoration = Arg2word;
    }

    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      GV.ERROR_OPCODE = UD_;
    }
    FillFlags(pMyDisasm, 53);
}

/* =======================================
 *   0c5h
 * ======================================= */
void __bea_callspec__ lds_GvM(PDISASM pMyDisasm)
{
    /* if MOD == 11b, invalid instruction */

    if (GV.Architecture == 64) {

        /* VEX2Bytes prefix */

        if (!Security(2, pMyDisasm)) return;
        if (GV.REX.state == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
          GV.ERROR_OPCODE = UD_;
        }
        GV.REX.R_ = ~((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 7) & 0x1;
        GV.VEX.vvvv = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0xF;
        GV.VEX.L = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 2) & 0x1;
        GV.VEX.pp = ((*((UInt8*)(UIntPtr) (GV.EIP_+1)))) & 0x3;
        GV.VEX.mmmmm = 0x1; /* Force OFh */

        GV.REX.state = InUsePrefix;
        GV.VEX.state = InUsePrefix;
        GV.VEX.opcode = 0xc5;

        if (GV.VEX.pp == 0x0) {
            GV.NB_PREFIX++;
            (*pMyDisasm).Prefix.Number++;
            GV.EIP_+=2;
            (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
            (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.pp == 0x1) {
            /* 66h */
            GV.EIP_+=1;
            (*pMyDisasm).Prefix.OperandSize = InUsePrefix;
            GV.EIP_++;
            (*pMyDisasm).Prefix.Number++;
            GV.NB_PREFIX++;
            GV.OriginalOperandSize = GV.OperandSize;  /* if GV.OperandSize is used as a mandatory prefix, keep the real operandsize value */
            if (GV.Architecture == 16) {
              GV.OperandSize = 32;
            }
            else {
              if (GV.OperandSize != 64) {
                GV.OperandSize = 16;
              }
            }
            (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
            (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
            GV.OperandSize = (GV.Architecture == 16) ? 16 : 32;
        }
        else if (GV.VEX.pp == 0x2) {
            /* F3h */
            GV.EIP_+=1;
            (*pMyDisasm).Prefix.RepPrefix = SuperfluousPrefix;
            GV.EIP_++;
            (*pMyDisasm).Prefix.Number++;
            GV.NB_PREFIX++;
            GV.PrefRepe = 1;
            (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
            (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
            GV.PrefRepe = 0;
        }
        else if (GV.VEX.pp == 0x3) {
            /* F2h */
            GV.EIP_+=1;
            (*pMyDisasm).Prefix.RepnePrefix = SuperfluousPrefix;
            GV.EIP_++;
            (*pMyDisasm).Prefix.Number++;
            GV.NB_PREFIX++;
            GV.PrefRepne = 1;
            (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
            (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
            GV.PrefRepne = 0;
        }
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lds ");
        #endif
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0c9h
 * ======================================= */
void __bea_callspec__ leave_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "leave ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand1.Registers.gpr = REG4;
    (*pMyDisasm).Operand1.OpSize = 32;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand2.Registers.special = REG5;
    (*pMyDisasm).Operand2.OpSize = 32;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lea_GvM(PDISASM pMyDisasm)
{

    /* if MOD == 11b, invalid instruction */

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lea ");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    (*pMyDisasm).Operand2.AccessMode = 0;

}

/* =======================================
 * 0c4h
 * ======================================= */
void __bea_callspec__ les_GvM(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {

      /* VEX3Bytes prefix */

      if (!Security(1, pMyDisasm)) return;
      if (GV.REX.state == InUsePrefix) {
        GV.ERROR_OPCODE = UD_;
      }
      if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.ERROR_OPCODE = UD_;
      }
      if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        GV.ERROR_OPCODE = UD_;
      }
      if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        GV.ERROR_OPCODE = UD_;
      }
      if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        GV.ERROR_OPCODE = UD_;
      }
      GV.REX.B_ = ~((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 5) & 0x1;
      GV.REX.X_ = ~((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x1;
      GV.REX.R_ = ~((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 7) & 0x1;
      GV.VEX.mmmmm = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x1F;

      if (!Security(2, pMyDisasm)) return;
      GV.REX.W_ = ((*((UInt8*)(UIntPtr) (GV.EIP_+2))) >> 7) & 0x1;
      GV.VEX.vvvv = ((*((UInt8*)(UIntPtr) (GV.EIP_+2))) >> 3) & 0xF;
      GV.VEX.L = ((*((UInt8*)(UIntPtr) (GV.EIP_+2))) >> 2) & 0x1;
      GV.VEX.pp = ((*((UInt8*)(UIntPtr) (GV.EIP_+2)))) & 0x3;

      if (GV.REX.W_ == 1) {
        GV.OperandSize = 64;
        GV.OriginalOperandSize = 64;
      }
      else {
        GV.OperandSize = 32;
        GV.OriginalOperandSize = 32;
      }

      GV.REX.state = InUsePrefix;
      GV.VEX.state = InUsePrefix;
      GV.VEX.opcode = 0xc4;

      if (GV.VEX.pp == 0x0) {
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.EIP_+=3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        if (GV.VEX.mmmmm == 0x1) {
          (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x2) {
          (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x3) {
          (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else {
          GV.ERROR_OPCODE = UD_;
          FailDecode(pMyDisasm);
        }
      }
      else if (GV.VEX.pp == 0x1) {
        /* 66h */
        GV.EIP_+=2;
        (*pMyDisasm).Prefix.OperandSize = InUsePrefix;
        GV.EIP_++;
        (*pMyDisasm).Prefix.Number++;
        GV.NB_PREFIX++;
        GV.OriginalOperandSize = GV.OperandSize;  /* if GV.OperandSize is used as a mandatory prefix, keep the real operandsize value */
        if (GV.Architecture == 16) {
          GV.OperandSize = 32;
        }
        else {
          if (GV.OperandSize != 64) {
            GV.OperandSize = 16;
          }
        }
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        if (GV.VEX.mmmmm == 0x1) {
          (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x2) {
          (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else if (GV.VEX.mmmmm == 0x3) {
          (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        }
        else {
          GV.ERROR_OPCODE = UD_;
          FailDecode(pMyDisasm);
        }
        GV.OperandSize = (GV.Architecture == 16) ? 16 : 32;
      }
      else if (GV.VEX.pp == 0x2) {
          /* F3h */
          GV.EIP_+=2;
          (*pMyDisasm).Prefix.RepPrefix = SuperfluousPrefix;
          GV.EIP_++;
          (*pMyDisasm).Prefix.Number++;
          GV.NB_PREFIX++;
          GV.PrefRepe = 1;
          if (!Security(0, pMyDisasm)) return;
          (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
          if (GV.VEX.mmmmm == 0x1) {
              (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else if (GV.VEX.mmmmm == 0x2) {
              (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else if (GV.VEX.mmmmm == 0x3) {
              (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else {
              GV.ERROR_OPCODE = UD_;
              FailDecode(pMyDisasm);
          }
          GV.PrefRepe = 0;
      }
      else if (GV.VEX.pp == 0x3) {
          /* F2h */
          GV.EIP_+=2;
          (*pMyDisasm).Prefix.RepnePrefix = SuperfluousPrefix;
          GV.EIP_++;
          (*pMyDisasm).Prefix.Number++;
          GV.NB_PREFIX++;
          GV.PrefRepne = 1;
          if (!Security(0, pMyDisasm)) return;
          (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
          if (GV.VEX.mmmmm == 0x1) {
              (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else if (GV.VEX.mmmmm == 0x2) {
              (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else if (GV.VEX.mmmmm == 0x3) {
              (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
          }
          else {
              GV.ERROR_OPCODE = UD_;
              FailDecode(pMyDisasm);
          }
          GV.PrefRepne = 0;
      }
      GV.OperandSize = 32;
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "les ");
        #endif
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0ach
 * ======================================= */
void __bea_callspec__ lodsb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsb ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Operand2.OpSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6;
    GV.EIP_++;
    FillFlags(pMyDisasm, 59);
}

/* =======================================
 *      0adh
 * ======================================= */
void __bea_callspec__ lodsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsq ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsd ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsw ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
}

/* =======================================
 *      0e2h
 * ======================================= */
void __bea_callspec__ loop_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loop ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
      MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
      CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
      if (MyAddress >= W64LIT (0x100000000)) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
          #endif
      }
      else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
          #endif
      }
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Operand1.OpSize = 8;
      (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG1;
      (*pMyDisasm).Instruction.AddrValue = MyAddress;
      GV.EIP_+=2;
      FillFlags(pMyDisasm, 60);
    }
    else {
      MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
      CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
      MyAddress = MyAddress & 0xffff;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
      #endif
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Operand1.OpSize = 8;
      (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG1;
      (*pMyDisasm).Instruction.AddrValue = MyAddress;
      GV.EIP_+=2;
      FillFlags(pMyDisasm, 60);
    }
}

/* =======================================
 *      0xe0
 * ======================================= */
void __bea_callspec__ loopne_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loopne ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
      MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
      CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
      if (MyAddress >= W64LIT (0x100000000)) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
          #endif
      }
      else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
          #endif
      }
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Operand1.OpSize = 8;
      (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG1;
      (*pMyDisasm).Instruction.AddrValue = MyAddress;
      GV.EIP_+=2;
      FillFlags(pMyDisasm, 61);
    }
    else {
      MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
      CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
      MyAddress = MyAddress & 0xffff;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
      #endif
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Operand1.OpSize = 8;
      (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG1;
      (*pMyDisasm).Instruction.AddrValue = MyAddress;
      GV.EIP_+=2;
      FillFlags(pMyDisasm, 61);
    }
}

/* =======================================
 *      0xe1
 * ======================================= */
void __bea_callspec__ loope_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loope ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Operand1.OpSize = 8;
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);
    }
    else {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Operand1.OpSize = 8;
        (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);

    }
}

/* =======================================
 *    0f 03
 * ======================================= */
void __bea_callspec__ lsl_GvEw(PDISASM pMyDisasm)
{
    Int32 i;
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lsl ");
    #endif

    GV.MemDecoration = Arg2word;
    i = GV.OperandSize;
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if ((GV.MOD_ == 0x3) && (GV.OperandSize == 64)){
      GV.OperandSize = 32;
    }
    MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
    GV.OperandSize = i;
    Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP+2;

    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      GV.ERROR_OPCODE = UD_;
    }
    FillFlags(pMyDisasm, 62);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lss_Mp(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lss ");
  #endif
  GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lfs_Mp(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lfs ");
  #endif
  GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lgs_Mp(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lgs ");
  #endif
  GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_RdCd(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GV.OperandSize = (GV.Architecture == 64) ? 64 : 32;
  if (!Security(1, pMyDisasm)) return;
  GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
  ModRM_3[GV.RM_](&(*pMyDisasm).Operand1, pMyDisasm);
  GV.Register_ = CR_REG;
  Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
  if (
    (GV.REGOPCODE == 1) ||
    (GV.REGOPCODE == 5) ||
    (GV.REGOPCODE == 6) ||
    (GV.REGOPCODE == 7) ||
    (GV.REGOPCODE >= 8)
  ) GV.ERROR_OPCODE = UD_;

  FillFlags(pMyDisasm,67);
  GV.EIP_ += 2;
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_RdDd(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GV.OperandSize = (GV.Architecture == 64) ? 64 : 32;
  if (!Security(1, pMyDisasm)) return;
  GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
  ModRM_3[GV.RM_](&(*pMyDisasm).Operand1, pMyDisasm);
  GV.Register_ = DR_REG;
  Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

  FillFlags(pMyDisasm,67);
  GV.EIP_ += 2;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_CdRd(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GV.OperandSize = (GV.Architecture == 64) ? 64 : 32;
  if (!Security(1, pMyDisasm)) return;
  GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
  ModRM_3[GV.RM_](&(*pMyDisasm).Operand2, pMyDisasm);
  GV.Register_ = CR_REG;
  Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
  if (
    (GV.REGOPCODE == 1) ||
    (GV.REGOPCODE == 5) ||
    (GV.REGOPCODE == 6) ||
    (GV.REGOPCODE == 7) ||
    (GV.REGOPCODE >= 8)
  ) GV.ERROR_OPCODE = UD_;

  FillFlags(pMyDisasm,67);
  GV.EIP_ += 2;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_DdRd(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GV.OperandSize = (GV.Architecture == 64) ? 64 : 32;
  if (!Security(1, pMyDisasm)) return;
  GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
  ModRM_3[GV.RM_](&(*pMyDisasm).Operand2, pMyDisasm);
  GV.Register_ = DR_REG;
  Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

  FillFlags(pMyDisasm,67);
  GV.EIP_ += 2;
}

/* =======================================
 *      88h
 * ======================================= */
void __bea_callspec__ mov_EbGb(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  EbGb(pMyDisasm);
}

/* =======================================
 *      89h
 * ======================================= */
void __bea_callspec__ mov_EvGv(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  EvGv(pMyDisasm);
}

/* =======================================
 *      8ah
 * ======================================= */
void __bea_callspec__ mov_GbEb(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GbEb(pMyDisasm);
}

/* =======================================
 *      8bh
 * ======================================= */
void __bea_callspec__ mov_GvEv(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GvEv(pMyDisasm);
}

/* =======================================
 *      0a0h
 * ======================================= */
void __bea_callspec__ mov_ALOb(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.MemDecoration = Arg2byte;
    GV.RM_ = 5;
    GV.MOD_= 0;

    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE ;
    (*pMyDisasm).Operand2.OpSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(8, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Operand2.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(4, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Operand2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Operand2.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers8Bits[0]);
        #endif
    }
    else {
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers8Bits[0+8]);
        #endif
    }

}

/* =======================================
 *      0a1h
 * ======================================= */
void __bea_callspec__ mov_eAXOv(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(8, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Operand2.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(4, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Operand2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Operand2.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            GV.MemDecoration = Arg2word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG8;
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            GV.MemDecoration = Arg2word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }

    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE ;
    if (GV.MemDecoration == 104) {
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.MemDecoration == 103) {
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else if (GV.MemDecoration == 102) {
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }

}

/* =======================================
 *      0a2h
 * ======================================= */
void __bea_callspec__ mov_ObAL(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.RM_ = 5;
    GV.MOD_= 0;

    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE ;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(8, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Operand1.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(4, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Operand1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Operand1.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers8Bits[0]);
        #endif
    }
    else {
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers8Bits[0+8]);
        #endif
    }

}

/* =======================================
 *      0a3h
 * ======================================= */
void __bea_callspec__ mov_OveAX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(8, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Operand1.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(4, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Operand1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand1.OpMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Operand1.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            GV.MemDecoration = Arg1word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG8;
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            GV.MemDecoration = Arg1word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }


    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE ;
    if (GV.MemDecoration == Arg1qword) {
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.MemDecoration == Arg1dword) {
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else if (GV.MemDecoration == Arg1word) {
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}

/* =======================================
 *      0b0h
 * ======================================= */
void __bea_callspec__ mov_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    ALIb(pMyDisasm);
}

/* =======================================
 *      0b1h
 * ======================================= */
void __bea_callspec__ mov_CLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8BitsLegacy[1]);
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG1;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b2h
 * ======================================= */
void __bea_callspec__ mov_DLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8BitsLegacy[2]);
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG2;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b3h
 * ======================================= */
void __bea_callspec__ mov_BLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8BitsLegacy[3]);
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG3;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b4h
 * ======================================= */
void __bea_callspec__ mov_AHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if (GV.REX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8Bits[4]);
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8BitsLegacy[4]);
      #endif
    }

    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand1.OpPosition = HighPosition;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b5h
 * ======================================= */
void __bea_callspec__ mov_CHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));

    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if (GV.REX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8Bits[5]);
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8BitsLegacy[5]);
      #endif
    }
    (*pMyDisasm).Operand1.OpPosition = HighPosition;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG1;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b6h
 * ======================================= */
void __bea_callspec__ mov_DHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if (GV.REX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8Bits[6]);
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8BitsLegacy[6]);
      #endif
    }
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG2;
    (*pMyDisasm).Operand1.OpPosition = HighPosition;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b7h
 * ======================================= */
void __bea_callspec__ mov_BHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if (GV.REX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8Bits[7]);
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers8BitsLegacy[7]);
      #endif
    }
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG3;
	(*pMyDisasm).Operand1.OpPosition = HighPosition;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}


/* =======================================
 *      0a4h
 * ======================================= */
void __bea_callspec__ movs_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsb ");
    #endif
    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Operand2.OpSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6+REG7;
    GV.EIP_++;
    FillFlags(pMyDisasm, 68);
}

/* =======================================
 *      0a5h
 * ======================================= */
void __bea_callspec__ movsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsq ");
        #endif
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
        #endif
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsw ");
        #endif
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
}

/* =======================================
 *      0fb6h
 * ======================================= */
void __bea_callspec__ movzx_GvEb(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx ");
    #endif
    GvEb(pMyDisasm);
}


/* =======================================
 *      0fbeh
 * ======================================= */
void __bea_callspec__ movsx_GvEb(PDISASM pMyDisasm)
{
    if (GV.VEX.state == InUsePrefix) {
      FailDecode(pMyDisasm);
      return;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx ");
    #endif
    GvEb(pMyDisasm);
}

/* =======================================
 *      0fbfh
 * ======================================= */
void __bea_callspec__ movsx_GvEw(PDISASM pMyDisasm)
{
    if (GV.VEX.state == InUsePrefix) {
      FailDecode(pMyDisasm);
      return;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx ");
    #endif
    GvEw(pMyDisasm);
}

/* =======================================
 *      0fb7h
 * ======================================= */
void __bea_callspec__ movzx_GvEw(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx ");
  #endif
  GvEw(pMyDisasm);
}


/* =======================================
 *      0b8h
 * ======================================= */
void __bea_callspec__ mov_REG(PDISASM pMyDisasm, const char * mnemonic, int reg_1, int reg_2, int index)
{
  UInt64 MyAddress;
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION + DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic);
  #endif

  (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE + ABSOLUTE_;
  if (GV.OperandSize == 64) {
    if (!Security(8, pMyDisasm)) return;
    MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.16llX",(Int64) MyAddress);
    #endif
    GV.EIP_+=9;
    (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    (*pMyDisasm).Operand1.OpSize = 64;
    (*pMyDisasm).Operand2.OpSize = 64;
  }
  else if (GV.OperandSize == 32) {
    if (!Security(4, pMyDisasm)) return;
    MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.8X",(Int64) MyAddress);
    #endif
    GV.EIP_+=5;
    (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    (*pMyDisasm).Operand1.OpSize = 32;
    (*pMyDisasm).Operand2.OpSize = 32;
  }
  else {
    if (!Security(2, pMyDisasm)) return;
    MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
    (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand2.OpMnemonic, "%.4X",(Int64) MyAddress);
    #endif
    GV.EIP_+=3;
    (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand2.OpSize = 16;
  }

  if (GV.REX.B_ == 0) {
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type =  GENERAL_REG;
    (*pMyDisasm).Operand1.Registers.gpr = reg_1;
    if (GV.OperandSize == 64) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[index]);
      #endif
    }
    else if (GV.OperandSize == 32) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[index]);
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[index]);
      #endif
    }
  }
  else {
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand1.Registers.gpr = reg_2;
    if (GV.OperandSize == 64) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[index+8]);
      #endif
    }
    else if (GV.OperandSize == 32) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[index+8]);
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((char*) (*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[index+8]);
      #endif
    }
  }

}

/* =======================================
 *      0b8h
 * ======================================= */
void __bea_callspec__ mov_EAX(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG0, REG8, 0);
}

/* =======================================
 *      0b9h
 * ======================================= */
void __bea_callspec__ mov_ECX(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG1, REG9, 1);
}

/* =======================================
 *      0bah
 * ======================================= */
void __bea_callspec__ mov_EDX(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG2, REG10, 2);
}

/* =======================================
 *      0bbh
 * ======================================= */
void __bea_callspec__ mov_EBX(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG3, REG11, 3);
}

/* =======================================
 *      0bch
 * ======================================= */
void __bea_callspec__ mov_ESP(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG4, REG12, 4);
}

/* =======================================
 *      0bdh
 * ======================================= */
void __bea_callspec__ mov_EBP(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG5, REG13, 5);
}

/* =======================================
 *      0beh
 * ======================================= */
void __bea_callspec__ mov_ESI(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG6, REG14, 6);
}

/* =======================================
 *      0bfh
 * ======================================= */
void __bea_callspec__ mov_EDI(PDISASM pMyDisasm)
{
  mov_REG(pMyDisasm, "mov ", REG7, REG15, 7);
}
/* =======================================
 *      0c6h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EbIb(PDISASM pMyDisasm)
{
  if (!Security(1, pMyDisasm)) return;
  GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
  if (GV.REGOPCODE == 0) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    EbIb(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      0c7h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EvIv(PDISASM pMyDisasm)
{
  if (!Security(1, pMyDisasm)) return;
  GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
  if (GV.REGOPCODE == 0) {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    EvIv(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      08ch
 * ======================================= */
void __bea_callspec__ mov_EwSreg(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GV.MemDecoration = Arg1word;
  GV.OperandSize = 16;
  MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
  GV.OperandSize = 32;
  GV.Register_ = SEGMENT_REG;
  Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

  GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* =======================================
 *      08eh
 * ======================================= */
void __bea_callspec__ mov_SregEw(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
  #endif
  GV.MemDecoration = Arg2word;
  GV.OperandSize = 16;
  MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
  GV.OperandSize = 32;
  GV.Register_ = SEGMENT_REG;
  Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

  GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* =======================================
 *      0f 41
 * ======================================= */
void __bea_callspec__ cmovno_(PDISASM pMyDisasm)
{

  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 1) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandb ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandd ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovno ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}




/* =======================================
 *  0f 42
 * ======================================= */
void __bea_callspec__ cmovb_(PDISASM pMyDisasm)
{

  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 1) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandnb ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandnw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandnd ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kandnq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovb ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }

}


/* =======================================
 *  0f 45
 * ======================================= */
void __bea_callspec__ cmovne_(PDISASM pMyDisasm)
{

  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 1) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "korb ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "korw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 1) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kord ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "korq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovne ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* =======================================
 *  0f 46
 * ======================================= */
void __bea_callspec__ cmovbe_(PDISASM pMyDisasm)
{

  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 1) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxnorb ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxnorw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxnord ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxnorq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovbe ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* =======================================
 *  0f 47
 * ======================================= */
void __bea_callspec__ cmovnbe_(PDISASM pMyDisasm)
{

  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 1) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxorb ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxorw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxord ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kxorq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnbe ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* =======================================
 *  0f 48
 * ======================================= */
void __bea_callspec__ cmovs_(PDISASM pMyDisasm)
{
  if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovs ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }

}


/* =======================================
 *  0f 4a
 * ======================================= */
void __bea_callspec__ cmovp_(PDISASM pMyDisasm)
{
  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 1) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kaddb ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kaddw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kaddd ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kaddq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovp ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }
}




/* =======================================
 *  0f 4b
 * ======================================= */
void __bea_callspec__ cmovnp_(PDISASM pMyDisasm)
{
  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 1) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kunpckbw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kunpckwd ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kunpckdq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GyEy(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnp ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }

}



/* =======================================
 *  0f 44
 * ======================================= */
void __bea_callspec__ cmove_(PDISASM pMyDisasm)
{

  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 0) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ == 0x3) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "knotb ");
          #endif
          GV.Register_ = OPMASK_REG;
          GxEx(pMyDisasm);
        }
        else if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "knotw ");
          #endif
          GV.Register_ = OPMASK_REG;
          GxEx(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        if (GV.VEX.pp == 0) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "knotq ");
          #endif
          GV.Register_ = OPMASK_REG;
          GxEx(pMyDisasm);
        }
        else if (GV.VEX.pp == 1) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "knotd ");
          #endif
          GV.Register_ = OPMASK_REG;
          GxEx(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmove ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
 *      90h
 * ==================================================================== */
void __bea_callspec__ nop_(PDISASM pMyDisasm)
{
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pause ");
        #endif
        GV.EIP_++;
    }
    else {
        if (GV.REX.B_ == 1) {
            if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
                (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
            }
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
            #endif

            if (GV.OperandSize == 64) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
                #endif

                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[0+8]);
                #endif
                GV.EIP_++;
                (*pMyDisasm).Operand2.AccessMode = WRITE;
                (*pMyDisasm).Operand1.OpSize = 64;
                (*pMyDisasm).Operand2.OpSize = 64;
            }
            else if (GV.OperandSize == 32) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
                #endif

                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[0+8]);
                #endif

                GV.EIP_++;
                (*pMyDisasm).Operand2.AccessMode = WRITE;
                (*pMyDisasm).Operand1.OpSize = 32;
                (*pMyDisasm).Operand2.OpSize = 32;
            }
            else {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
                #endif

                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[0+8]);
                #endif

                GV.EIP_++;
                (*pMyDisasm).Operand2.AccessMode = WRITE;
                (*pMyDisasm).Operand1.OpSize = 16;
                (*pMyDisasm).Operand2.OpSize = 16;
            }

        }
        else {
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "nop ");
            #endif
            (*pMyDisasm).Operand1.AccessMode = READ;
            GV.EIP_++;
        }
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ nop_Ev(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "nop ");
  #endif
  if (GV.OperandSize == 64) {
      GV.MemDecoration = Arg2qword;
  }
  else if (GV.OperandSize == 32) {
      GV.MemDecoration = Arg2dword;
  }
  else {
      GV.MemDecoration = Arg2word;
  }
  MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
  GV.EIP_ += GV.DECALAGE_EIP+2;
  (*pMyDisasm).Operand2.AccessMode = 0;
  (*pMyDisasm).Operand1.AccessMode = READ;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ hint_nop(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hint_nop ");
  #endif
  if (GV.OperandSize == 64) {
      GV.MemDecoration = Arg2qword;
  }
  else if (GV.OperandSize == 32) {
      GV.MemDecoration = Arg2dword;
  }
  else {
      GV.MemDecoration = Arg2word;
  }
  MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
  (*pMyDisasm).Operand1.AccessMode = READ;
  GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ nop_1e(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  else if (GV.PrefRepe == 1) {
    /* ======= prefix f3 ========= */
    if (!Security(1, pMyDisasm)) return;
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 1) {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = CET_INSTRUCTION;
      if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }
      if ((GV.REX.state == InUsePrefix) && (GV.REX.W_ == 1)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rdsspq ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rdsspd ");
        #endif
      }
      GV.OperandSize = (GV.REX.W_ == 1) ? 64 : 32;
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand2.OpSize = 64;
      (*pMyDisasm).Operand2.Registers.type = SPECIAL_REG;
      (*pMyDisasm).Operand2.Registers.special = REG2; /* SSP reg */
    }
    else if (GV.REGOPCODE == 7) {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
      if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }
      if (GV.RM_ == 0x2) {
        (*pMyDisasm).Instruction.Category = CET_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "endbr64 ");
        #endif
        GV.EIP_+= GV.DECALAGE_EIP+2;
      }
      else if (GV.RM_ == 0x3) {
        (*pMyDisasm).Instruction.Category = CET_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "endbr32 ");
        #endif
        GV.EIP_+= GV.DECALAGE_EIP+2;
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hint_nop ");
    #endif
    if (GV.OperandSize == 64) {
      GV.MemDecoration = Arg2qword;
    }
    else if (GV.OperandSize == 32) {
      GV.MemDecoration = Arg2dword;
    }
    else {
      GV.MemDecoration = Arg2word;
    }
    MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
    (*pMyDisasm).Operand1.AccessMode = READ;
    GV.EIP_ += GV.DECALAGE_EIP+2;
  }
}

/* =======================================
 *      08h
 * ======================================= */
void __bea_callspec__ or_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "or ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,74);
}

/* =======================================
 *      09h
 * ======================================= */
void __bea_callspec__ or_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "or ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,74);
}

/* =======================================
 *      0ah
 * ======================================= */
void __bea_callspec__ or_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "or ");
    #endif
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,74);
}

/* =======================================
 *      0bh
 * ======================================= */
void __bea_callspec__ or_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "or ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,74);
}

/* =======================================
 *      0ch
 * ======================================= */
void __bea_callspec__ or_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "or ");
    #endif
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,74);
}

/* =======================================
 *      0dh
 * ======================================= */
void __bea_callspec__ or_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "or ");
    #endif
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,74);
}


/* =======================================
 *      06eh
 * ======================================= */
void __bea_callspec__ outsb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "outsb ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG2;
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_++;
    FillFlags(pMyDisasm, 76);
}

/* =======================================
 *      06fh
 * ======================================= */
void __bea_callspec__ outsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    if (GV.OperandSize >= 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "outsd ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG2;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 32;
        GV.EIP_++;
        FillFlags(pMyDisasm, 76);
    }

    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "outsw ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG2;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Operand2.OpSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, 76);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ out_IbAL(PDISASM pMyDisasm)
{
    long MyNumber;

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "out ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers8Bits[0]);
    #endif
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand2.Registers.gpr = REGS[0];
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ out_Ib_eAX(PDISASM pMyDisasm)
{
    long MyNumber;

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "out ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Instruction.Immediat = MyNumber;

    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand2.Registers.gpr = REGS[0];

    if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[0]);
        #endif
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[0]);
        #endif
        (*pMyDisasm).Operand2.OpSize = 16;
    }
    GV.EIP_ += 2;
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ out_DXAL(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "out ");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[2]);
    #endif
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.AccessMode = READ;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers8Bits[0]);
    #endif
    (*pMyDisasm).Operand2.OpSize = 8;
    GV.EIP_ ++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ out_DXeAX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "out ");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[2]);
    #endif
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.AccessMode = READ;
    if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[0]);
        #endif
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[0]);
        #endif
        (*pMyDisasm).Operand2.OpSize = 16;
    }
    GV.EIP_ ++;
}

/* =======================================
 *      8fh
 * ======================================= */
void __bea_callspec__ pop_Ev(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  if (!Security(1, pMyDisasm)) return;
  GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
  if (GV.REGOPCODE == 0) {
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pop ");
    #endif
    if (GV.Architecture == 64) {
      GV.OperandSize = 64;
      GV.MemDecoration = Arg1qword;
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand2.OpSize = 64;
      (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
    else if (GV.OperandSize == 32) {
      GV.MemDecoration = Arg1dword;
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand2.OpSize = 32;
      (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
    else {
      GV.MemDecoration = Arg1word;
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand2.OpSize = 16;
      (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      58h-5fh
 * ======================================= */
void __bea_callspec__ pop_reg(PDISASM pMyDisasm, int index)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pop ");
    #endif
    if (GV.Architecture == 64) {
      switch(GV.OperandSize) {
        case 64:

        case 32:
          if (GV.REX.B_ == 0) {
              #ifndef BEA_LIGHT_DISASSEMBLY
                 (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[index]);
              #endif
              (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
              (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
              (*pMyDisasm).Operand1.Registers.gpr = REGS[index];
          }
          else {
              #ifndef BEA_LIGHT_DISASSEMBLY
                 (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[index+8]);
              #endif
              (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
              (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
              (*pMyDisasm).Operand1.Registers.gpr = REGS[index+8];
          }
          (*pMyDisasm).Operand1.OpSize = 64;
          (*pMyDisasm).Operand2.OpSize = 64;
          break;

        case 16:
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[index]);
          #endif
          (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
          (*pMyDisasm).Operand1.Registers.gpr = REGS[index];
          (*pMyDisasm).Operand1.OpSize = 16;
          (*pMyDisasm).Operand2.OpSize = 16;
      }
    }
    else {
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[index]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[index];
            (*pMyDisasm).Operand1.OpSize = 32;
            (*pMyDisasm).Operand2.OpSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[index]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
            (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
            (*pMyDisasm).Operand1.Registers.gpr = REGS[index];
            (*pMyDisasm).Operand1.OpSize = 16;
            (*pMyDisasm).Operand2.OpSize = 16;
        }
    }
    GV.EIP_++;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
}

/* =======================================
 *      58h
 * ======================================= */
void __bea_callspec__ pop_eax(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 0);
}

/* =======================================
 *      59h
 * ======================================= */
void __bea_callspec__ pop_ecx(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 1);
}

/* =======================================
 *      5ah
 * ======================================= */
void __bea_callspec__ pop_edx(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 2);
}

/* =======================================
 *      5bh
 * ======================================= */
void __bea_callspec__ pop_ebx(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 3);
}

/* =======================================
 *      5ch
 * ======================================= */
void __bea_callspec__ pop_esp(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 4);
}

/* =======================================
 *      5dh
 * ======================================= */
void __bea_callspec__ pop_ebp(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 5);
}

/* =======================================
 *      5eh
 * ======================================= */
void __bea_callspec__ pop_esi(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 6);
}

/* =======================================
 *      5fh
 * ======================================= */
void __bea_callspec__ pop_edi(PDISASM pMyDisasm)
{
  pop_reg(pMyDisasm, 7);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ pop_es(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pop ");
      #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[0]);
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = SEGMENT_REG;
        (*pMyDisasm).Operand1.Registers.segment = REGS[0];
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ pop_ss(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pop ");
      #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[2]);
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = SEGMENT_REG;
        (*pMyDisasm).Operand1.Registers.segment = REGS[2];
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ pop_ds(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pop ");
      #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[3]);
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = SEGMENT_REG;
        (*pMyDisasm).Operand1.Registers.segment = REGS[3];
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ pop_fs(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {

    if (GV.Architecture == 64) {
      FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pop ");
      #endif
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[4]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = SEGMENT_REG;
      (*pMyDisasm).Operand1.Registers.segment = REGS[4];
      (*pMyDisasm).Operand1.OpSize = 16;
      (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand2.OpSize = 16;
      (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
      GV.EIP_++;
    }
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ pop_gs(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pop ");
    #endif
    if (GV.Architecture == 64) {
      FailDecode(pMyDisasm);
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[5]);
      #endif
      (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand1.Registers.type = SEGMENT_REG;
      (*pMyDisasm).Operand1.Registers.segment = REGS[5];
      (*pMyDisasm).Operand1.OpSize = 16;
      (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand2.OpSize = 16;
      (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
      GV.EIP_++;
    }
  }
}

/* =======================================
 *      9dh
 * ======================================= */
void __bea_callspec__ popfd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;

    if (GV.Architecture == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popfq ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
        (*pMyDisasm).Operand1.Registers.special = REG0;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 64;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        FillFlags(pMyDisasm, 78);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popfd ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
        (*pMyDisasm).Operand1.Registers.special = REG0;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        FillFlags(pMyDisasm, 78);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popf ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
        (*pMyDisasm).Operand1.Registers.special = REG0;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        FillFlags(pMyDisasm, 78);
    }
}

/* =======================================
 *      9dh
 * ======================================= */
void __bea_callspec__ popad_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else if (GV.OperandSize == 32) {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;

        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popad ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
        (*pMyDisasm).Operand1.Registers.gpr = REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;

        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popa ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
        (*pMyDisasm).Operand1.Registers.gpr = REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ push_es(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
      #endif

      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[0]);
      #endif
      (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand2.Registers.type = SEGMENT_REG;
      (*pMyDisasm).Operand2.Registers.segment = REGS[0];
      (*pMyDisasm).Operand2.OpSize = 16;
      (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand1.OpSize = 16;
      (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
      GV.EIP_++;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ push_ss(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
      #endif

      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[2]);
      #endif
      (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand2.Registers.type = SEGMENT_REG;
      (*pMyDisasm).Operand2.Registers.segment = REGS[2];
      (*pMyDisasm).Operand2.OpSize = 16;
      (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand1.OpSize = 16;
      (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
      GV.EIP_++;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ push_ds(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
      #endif
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[3]);
      #endif
      (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand2.Registers.type = SEGMENT_REG;
      (*pMyDisasm).Operand2.Registers.segment = REGS[3];
      (*pMyDisasm).Operand2.OpSize = 16;
      (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand1.OpSize = 16;
      (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
      GV.EIP_++;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ push_fs(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    if (GV.Architecture == 64) {
      FailDecode(pMyDisasm);
    }
    else {
      (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
      #endif
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[4]);
      #endif
      (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
      (*pMyDisasm).Operand2.Registers.type = SEGMENT_REG;
      (*pMyDisasm).Operand2.Registers.segment = REGS[4];
      (*pMyDisasm).Operand2.OpSize = 16;
      (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
      (*pMyDisasm).Operand1.OpSize = 16;
      (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
      (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
      GV.EIP_++;
    }
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ push_gs(PDISASM pMyDisasm)
{
  if (GV.Architecture == 64) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[5]);
    #endif
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand2.Registers.type = SEGMENT_REG;
    (*pMyDisasm).Operand2.Registers.segment = REGS[5];
    (*pMyDisasm).Operand2.OpSize = 16;
    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    GV.EIP_++;
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ push_cs(PDISASM pMyDisasm)
{
  if (GV.Architecture == 64) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Operand1.OpMnemonic, RegistersSEG[1]);
    #endif
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand2.Registers.type = SEGMENT_REG;
    (*pMyDisasm).Operand2.Registers.segment = REGS[1];
    (*pMyDisasm).Operand2.OpSize = 16;
    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    GV.EIP_++;
  }
}

void __bea_callspec__ push_reg(PDISASM pMyDisasm, int index)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
  #endif
  if (GV.Architecture == 64) {
      switch(GV.OperandSize) {
        case 64:
        case 32:
          if (GV.REX.B_ == 0) {
              #ifndef BEA_LIGHT_DISASSEMBLY
                 (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[index]);
              #endif
              (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
              (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
              (*pMyDisasm).Operand2.Registers.gpr = REGS[index];
          }
          else {
              #ifndef BEA_LIGHT_DISASSEMBLY
                 (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[index+8]);
              #endif
              (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
              (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
              (*pMyDisasm).Operand2.Registers.gpr = REGS[index+8];
          }
          (*pMyDisasm).Operand2.OpSize = 64;
          (*pMyDisasm).Operand1.OpSize = 64;
          break;
        case 16:
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[index]);
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
          (*pMyDisasm).Operand2.Registers.gpr = REGS[index];
          (*pMyDisasm).Operand2.OpSize = 16;
          (*pMyDisasm).Operand1.OpSize = 16;
      }

  }
  else {
      if (GV.OperandSize == 32) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[index]);
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
          (*pMyDisasm).Operand2.Registers.gpr = REGS[index];
          (*pMyDisasm).Operand2.OpSize = 32;
          (*pMyDisasm).Operand1.OpSize = 32;
      }
      else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy((char*) &(*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[index]);
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
          (*pMyDisasm).Operand2.Registers.gpr = REGS[index];
          (*pMyDisasm).Operand2.OpSize = 16;
          (*pMyDisasm).Operand1.OpSize = 16;
      }
  }
  GV.EIP_++;
  (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
  (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
  (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG;
  (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
}

/* =======================================
 *      50h
 * ======================================= */
void __bea_callspec__ push_eax(PDISASM pMyDisasm)
{
  push_reg(pMyDisasm, 0);
}

/* =======================================
 *      51h
 * ======================================= */
void __bea_callspec__ push_ecx(PDISASM pMyDisasm)
{
  push_reg(pMyDisasm, 1);
}

/* =======================================
 *      52h
 * ======================================= */
void __bea_callspec__ push_edx(PDISASM pMyDisasm)
{
  push_reg(pMyDisasm, 2);
}

/* =======================================
 *      53h
 * ======================================= */
void __bea_callspec__ push_ebx(PDISASM pMyDisasm)
{
  push_reg(pMyDisasm, 3);
}

/* =======================================
 *      54h
 * ======================================= */
void __bea_callspec__ push_esp(PDISASM pMyDisasm)
{
  push_reg(pMyDisasm, 4);
}

/* =======================================
 *      55h
 * ======================================= */
void __bea_callspec__ push_ebp(PDISASM pMyDisasm)
{
    push_reg(pMyDisasm, 5);
}

/* =======================================
 *      56h
 * ======================================= */
void __bea_callspec__ push_esi(PDISASM pMyDisasm)
{
  push_reg(pMyDisasm, 6);
}

/* =======================================
 *      57h
 * ======================================= */
void __bea_callspec__ push_edi(PDISASM pMyDisasm)
{
  push_reg(pMyDisasm, 7);
}


/* =======================================
 *      68h
 * ======================================= */
void __bea_callspec__ push_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;

    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
    #endif
    if (GV.Architecture == 64) {
        if (!Security(4, pMyDisasm)) return;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.8X",(Int64)*((UInt32*)(UIntPtr) (GV.EIP_+1)));
        #endif
        GV.ImmediatSize = 32;
        (*pMyDisasm).Instruction.Immediat = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        GV.EIP_ += 5;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Operand2.OpSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(4, pMyDisasm)) return;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.8X",(Int64)*((UInt32*)(UIntPtr) (GV.EIP_+1)));
        #endif
        GV.ImmediatSize = 32;
        (*pMyDisasm).Instruction.Immediat = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        GV.EIP_ += 5;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.4X",(Int64)*((UInt16*)(UIntPtr) (GV.EIP_+1)));
        #endif
        GV.ImmediatSize = 16;
        (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_+1));
        GV.EIP_ += 3;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
}

/* =======================================
 *      6ah
 * ======================================= */
void __bea_callspec__ push_Ib(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand2.OpMnemonic,"%.8X",(Int64)*((Int8*)(IntPtr) (GV.EIP_+1)));
    #endif
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    GV.EIP_ += 2;
    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand1.OpSize = 32;
    (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
    (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand2.OpSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;

}


/* =======================================
 *      9ch
 * ======================================= */
void __bea_callspec__ pushfd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;

    if (GV.Architecture == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pushfq ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand2.Registers.special = REG0;
        (*pMyDisasm).Operand2.OpSize = 64;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        FillFlags(pMyDisasm, 78);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pushfd ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand2.Registers.special = REG0;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        FillFlags(pMyDisasm, 78);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pushf ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand2.Registers.special = REG0;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
        FillFlags(pMyDisasm, 78);
    }
}


/* =======================================
 *      60h
 * ======================================= */
void __bea_callspec__ pushad_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pushad ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pusha ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
    }
}

/* =======================================
 *      0c2h
 * ======================================= */
void __bea_callspec__ retn_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "retn ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic,"%.4X",(Int64)*((UInt16*)(UIntPtr) (GV.EIP_+1)));
    #endif
    GV.ImmediatSize = 16;
    (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_+1));
    GV.EIP_+=3;
    (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
}

/* =======================================
 *      0c3h
 * ======================================= */
void __bea_callspec__ ret_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ret ");
    #endif
    GV.EIP_++;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.OpSize = 32;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ retf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    if (GV.SYNTAX_ == ATSyntax) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lret ");
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "retf ");
        #endif
    }
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "retf ");
    #endif
    GV.EIP_++;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.OpSize = 32;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG4;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ retf_Iw(PDISASM pMyDisasm)
{
    int i = 0;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    if (GV.SYNTAX_ == ATSyntax) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lret ");
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "retf ");
        #endif
    }
    if (!Security(2, pMyDisasm)) return;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Operand1.OpMnemonic+i,"%.4X",(Int64)*((UInt16*)(UIntPtr) (GV.EIP_+1)));
    #endif
    GV.ImmediatSize = 16;
    (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_+1));
    GV.EIP_+=3;
    (*pMyDisasm).Operand1.OpType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Operand1.OpSize = 16;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG4;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ rdtsc_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rdtsc ");
  #endif
  GV.EIP_++;
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0+REG2;
  (*pMyDisasm).Operand1.OpSize = 32;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ rdmsr_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rdmsr ");
  #endif
  GV.EIP_++;
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0+REG2;
  (*pMyDisasm).Operand1.OpSize = 32;
  (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG1;
  (*pMyDisasm).Operand2.OpSize = 32;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ rdpmc_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rdpmc ");
  #endif
  GV.EIP_++;
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0+REG2;
  (*pMyDisasm).Operand1.OpSize = 32;
  (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG1;
  (*pMyDisasm).Operand2.OpSize = 32;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ rsm_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rsm ");
  #endif
  GV.EIP_++;
  FillFlags(pMyDisasm, 89);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ sysenter_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sysenter ");
  #endif
  GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ sysexit_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sysexit ");
  #endif
  GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ sahf_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sahf ");
  #endif
  GV.EIP_++;
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand1.Registers.special = REG0;
  (*pMyDisasm).Operand1.OpSize = 32;
  (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
  (*pMyDisasm).Operand2.OpSize = 8;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ salc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = UNDOCUMENTED_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "salc ");
    #endif
    GV.EIP_++;
}


/* =======================================
 *      0ach
 * ======================================= */
void __bea_callspec__ scasb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "scasb ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Operand1.AccessMode = READ;
    (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand2.Memory.BaseRegister = REG7;
    (*pMyDisasm).Operand2.OpSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
    GV.EIP_++;
    FillFlags(pMyDisasm, 94);
}

/* =======================================
 *      0adh
 * ======================================= */
void __bea_callspec__ scas_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "scasq ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand2.OpSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 94);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "scasd ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 94);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "scasw ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand1.AccessMode = READ;
        (*pMyDisasm).Operand2.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand2.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 94);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ stc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "stc ");
    #endif
    GV.EIP_++;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand1.Registers.special = REG0;
    (*pMyDisasm).Operand1.OpSize = 1;
    FillFlags(pMyDisasm, 98);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ sti_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sti ");
    #endif
    GV.EIP_++;
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand1.Registers.special = REG0;
    (*pMyDisasm).Operand1.OpSize = 1;
    FillFlags(pMyDisasm, 100);
}


/* =======================================
 *      0aah
 * ======================================= */
void __bea_callspec__ stos_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "stosb ");
    #endif
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpSize = 8;
    (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
    (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Operand1.OpSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
    GV.EIP_++;
    FillFlags(pMyDisasm, 101);
}

/* =======================================
 *      0abh
 * ======================================= */
void __bea_callspec__ stosw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "stosq ");
        #endif
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
        (*pMyDisasm).Operand2.OpSize = 64;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 101);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "stosd ");
        #endif
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
        (*pMyDisasm).Operand2.OpSize = 32;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 101);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "stosw ");
        #endif
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG0;
        (*pMyDisasm).Operand2.OpSize = 16;
        (*pMyDisasm).Operand1.OpType = MEMORY_TYPE;
        (*pMyDisasm).Operand1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = GENERAL_REG; (*pMyDisasm).Instruction.ImplicitModifiedRegs.gpr = REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 101);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ syscall_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
    if (GV.Architecture == 64) {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION+CONTROL_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "syscall ");
        #endif
        GV.EIP_++;
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG1+REG11;
        (*pMyDisasm).Operand1.OpSize = 64;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ sysret_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if (GV.Architecture == 64) {
      (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sysret ");
      #endif
      GV.EIP_++;
      (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG1+REG11;
      (*pMyDisasm).Operand2.OpSize = 64;
  }
  else {
      FailDecode(pMyDisasm);
  }
}



/* =======================================
 *      18h
 * ======================================= */
void __bea_callspec__ sbb_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sbb ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,93);
}

/* =======================================
 *      19h
 * ======================================= */
void __bea_callspec__ sbb_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sbb ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,93);
}

/* =======================================
 *      1ah
 * ======================================= */
void __bea_callspec__ sbb_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sbb ");
    #endif
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,93);
}

/* =======================================
 *      1bh
 * ======================================= */
void __bea_callspec__ sbb_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sbb ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,93);
}

/* =======================================
 *      1ch
 * ======================================= */
void __bea_callspec__ sbb_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sbb ");
    #endif
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,93);
}

/* =======================================
 *      1dh
 * ======================================= */
void __bea_callspec__ sbb_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sbb ");
    #endif
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,93);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ seto_(PDISASM pMyDisasm)
{
  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 0) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (GV.REX.W_ == 0) {
      if (GV.VEX.pp == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovb ");
        #endif
        GV.MemDecoration = Arg2byte;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else if (GV.VEX.pp == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovw ");
        #endif
        GV.MemDecoration = Arg2word;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      if (GV.VEX.pp == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovd ");
        #endif
        GV.MemDecoration = Arg2dword;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else if (GV.VEX.pp == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovq ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "seto ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      0f91h
 * ======================================= */
void __bea_callspec__ setno_(PDISASM pMyDisasm)
{

  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 0)
    ) {
      if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_ != 0x3) {
        if (GV.REX.W_ == 0) {
          if (GV.VEX.pp == 1) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovb ");
            #endif
            GV.MemDecoration = Arg1byte;
            GV.Register_ = OPMASK_REG;
            ExGx(pMyDisasm);
          }
          else if (GV.VEX.pp == 0) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovw ");
            #endif
            GV.MemDecoration = Arg1word;
            GV.Register_ = OPMASK_REG;
            ExGx(pMyDisasm);
          }
          else {
            FailDecode(pMyDisasm);
          }
        }
        else {
          if (GV.VEX.pp == 1) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovd ");
            #endif
            GV.MemDecoration = Arg1dword;
            GV.Register_ = OPMASK_REG;
            ExGx(pMyDisasm);
          }
          else if (GV.VEX.pp == 0) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovq ");
            #endif
            GV.MemDecoration = Arg1qword;
            GV.Register_ = OPMASK_REG;
            ExGx(pMyDisasm);
          }
          else {
            FailDecode(pMyDisasm);
          }
        }
      }
      else {
        FailDecode(pMyDisasm);
      }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setno ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      0f 92h
 * ======================================= */
void __bea_callspec__ setb_(PDISASM pMyDisasm)
{
  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 0)
    ) {
      if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_ == 0x3) {
        if (GV.REX.W_ == 0) {
          if (GV.VEX.pp == 1) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovb ");
            #endif
            GV.OperandSize = 32;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else if (GV.VEX.pp == 0) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovw ");
            #endif
            GV.OperandSize = 32;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else if (GV.VEX.pp == 3) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovd ");
            #endif
            GV.OperandSize = 32;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else {
            FailDecode(pMyDisasm);
          }
        }
        else {
          if (GV.VEX.pp == 3) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovq ");
            #endif
            GV.OperandSize = 64;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else {
            FailDecode(pMyDisasm);
          }
        }
      }
      else {
        FailDecode(pMyDisasm);
      }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setb ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* =======================================
 *      0f 93h
 * ======================================= */
void __bea_callspec__ setnb_(PDISASM pMyDisasm)
{
  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 0)
    ) {
      if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_ == 0x3) {
        if (GV.REX.W_ == 0) {
          if (GV.VEX.pp == 1) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovb ");
            #endif
            GV.OperandSize = 32;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else if (GV.VEX.pp == 0) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovw ");
            #endif
            GV.OperandSize = 32;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else if (GV.VEX.pp == 3) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovd ");
            #endif
            GV.OperandSize = 32;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else {
            FailDecode(pMyDisasm);
          }
        }
        else {
          if (GV.VEX.pp == 3) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kmovq ");
            #endif
            GV.OperandSize = 64;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            GV.Register_ = OPMASK_REG;
            Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
            GV.EIP_ += GV.DECALAGE_EIP+2;
          }
          else {
            FailDecode(pMyDisasm);
          }
        }
      }
      else {
        FailDecode(pMyDisasm);
      }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setnb ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ sete_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sete ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setne_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setne ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setbe_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setbe ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setnbe_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setnbe ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f 98h
 * ======================================= */
void __bea_callspec__ sets_(PDISASM pMyDisasm)
{
  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 0) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (GV.REX.W_ == 0) {
      if (GV.VEX.pp == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kortestb ");
        #endif
        GV.MemDecoration = Arg2byte;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else if (GV.VEX.pp == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kortestw ");
        #endif
        GV.MemDecoration = Arg2word;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      if (GV.VEX.pp == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kortestd ");
        #endif
        GV.MemDecoration = Arg2dword;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else if (GV.VEX.pp == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kortestq ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sets ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setns_(PDISASM pMyDisasm)
{
  if (
      (GV.EVEX.state != InUsePrefix) &&
      (GV.VEX.state == InUsePrefix) &&
      (GV.VEX.L == 0) &&
      (((GV.VEX.vvvv >> 3) & 0x1) == 1)
    ) {
    if (GV.REX.W_ == 0) {
      if (GV.VEX.pp == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ktestb ");
        #endif
        GV.MemDecoration = Arg2byte;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        (*pMyDisasm).Operand1.AccessMode = READ;
      }
      else if (GV.VEX.pp == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ktestw ");
        #endif
        GV.MemDecoration = Arg2word;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        (*pMyDisasm).Operand1.AccessMode = READ;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      if (GV.VEX.pp == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ktestd ");
        #endif
        GV.MemDecoration = Arg2dword;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        (*pMyDisasm).Operand1.AccessMode = READ;
      }
      else if (GV.VEX.pp == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ktestq ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        (*pMyDisasm).Operand1.AccessMode = READ;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
  }
  else if (GV.VEX.state != InUsePrefix){
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setns ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setp_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setp ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setnp_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setnp ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setge_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setnl ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.OperandSize = 32;
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setnge_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setl ");
  #endif
  GV.MemDecoration = Arg1byte;
  GV.OperandSize = 8;
  MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
  GV.OperandSize = 32;
  GV.EIP_+= GV.DECALAGE_EIP+2;
  FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setle_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setle ");
  #endif
  GV.MemDecoration = Arg1byte;
  GV.OperandSize = 8;
  MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
  GV.OperandSize = 32;
  GV.EIP_+= GV.DECALAGE_EIP+2;
  FillFlags(pMyDisasm,95);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ setnle_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "setnle ");
  #endif
  GV.MemDecoration = Arg1byte;
  GV.OperandSize = 8;
  MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
  GV.OperandSize = 32;
  GV.EIP_+= GV.DECALAGE_EIP+2;
  FillFlags(pMyDisasm,95);
}


/* =======================================
 *      0fa4h
 * ======================================= */
void __bea_callspec__ shld_EvGvIb(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shld ");
  #endif
  GV.ImmediatSize = 8;
  EvGv(pMyDisasm);
  GV.EIP_+= 1;
  if (!Security(0, pMyDisasm)) return;

  (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand3.OpMnemonic, "%.8X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
  #endif
  (*pMyDisasm).Operand3.OpType = CONSTANT_TYPE+ABSOLUTE_;
  (*pMyDisasm).Operand3.OpSize = 8;

  FillFlags(pMyDisasm, 97);
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ shld_EvGvCL(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shld ");
  #endif
  EvGv(pMyDisasm);
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Operand3.OpMnemonic, Registers8Bits[1]);
  #endif
  (*pMyDisasm).Operand3.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand3.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand3.Registers.gpr = REG1;
  (*pMyDisasm).Operand3.OpSize = 8;
  FillFlags(pMyDisasm, 97);
}

/* =======================================
 *      0fach
 * ======================================= */
void __bea_callspec__ shrd_EvGvIb(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shrd ");
  #endif
  GV.ImmediatSize = 8;
  EvGv(pMyDisasm);
  GV.EIP_+= 1;
  if (!Security(0, pMyDisasm)) return;

  (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand3.OpMnemonic, "%.8X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
  #endif
  (*pMyDisasm).Operand3.OpType = CONSTANT_TYPE+ABSOLUTE_;
  (*pMyDisasm).Operand3.OpSize = 8;

  FillFlags(pMyDisasm, 97);
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ shrd_EvGvCL(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shrd ");
  #endif
  EvGv(pMyDisasm);
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Operand3.OpMnemonic, Registers8Bits[1]);
  #endif
  (*pMyDisasm).Operand3.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand3.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand3.Registers.gpr = REG1;
  (*pMyDisasm).Operand3.OpSize = 8;
  FillFlags(pMyDisasm, 97);
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ std_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "std ");
  #endif
  GV.EIP_++;
  (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = SPECIAL_REG;
  (*pMyDisasm).Operand1.Registers.special = REG0;
  (*pMyDisasm).Operand1.OpSize = 1;
  FillFlags(pMyDisasm, 99);
}


/* =======================================
 *      28h
 * ======================================= */
void __bea_callspec__ sub_EbGb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sub ");
  #endif
  EbGb(pMyDisasm);
  FillFlags(pMyDisasm,103);
}

/* =======================================
 *      29h
 * ======================================= */
void __bea_callspec__ sub_EvGv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sub ");
  #endif
  EvGv(pMyDisasm);
  FillFlags(pMyDisasm,103);
}

/* =======================================
 *      2ah
 * ======================================= */
void __bea_callspec__ sub_GbEb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sub ");
  #endif
  GbEb(pMyDisasm);
  FillFlags(pMyDisasm,103);
}

/* =======================================
 *      2bh
 * ======================================= */
void __bea_callspec__ sub_GvEv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sub ");
  #endif
  GvEv(pMyDisasm);
  FillFlags(pMyDisasm,103);
}

/* =======================================
 *      2ch
 * ======================================= */
void __bea_callspec__ sub_ALIb(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sub ");
  #endif
  ALIb(pMyDisasm);
  FillFlags(pMyDisasm,103);
}

/* =======================================
 *      2dh
 * ======================================= */
void __bea_callspec__ sub_eAX_Iv(PDISASM pMyDisasm)
{
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sub ");
  #endif
  eAX_Iv(pMyDisasm);
  FillFlags(pMyDisasm,103);
}

/* =======================================
 *      84h
 * ======================================= */
void __bea_callspec__ test_EbGb(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
  #endif
  (*pMyDisasm).Operand1.AccessMode = READ;
  EbGb(pMyDisasm);
  FillFlags(pMyDisasm,104);
}

/* =======================================
 *      85h
 * ======================================= */
void __bea_callspec__ test_EvGv(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
  #endif
  (*pMyDisasm).Operand1.AccessMode = READ;
  EvGv(pMyDisasm);
  FillFlags(pMyDisasm,104);
}

/* =======================================
 *      86h
 * ======================================= */
void __bea_callspec__ test_GbEb(PDISASM pMyDisasm)
{
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
  #endif
  (*pMyDisasm).Operand1.AccessMode = READ;
  GbEb(pMyDisasm);
  FillFlags(pMyDisasm,104);
}

/* =======================================
 *      87h
 * ======================================= */
void __bea_callspec__ test_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
    #endif
    (*pMyDisasm).Operand1.AccessMode = READ;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,104);
}

/* =======================================
 *      88h
 * ======================================= */
void __bea_callspec__ test_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
    #endif
    (*pMyDisasm).Operand1.AccessMode = READ;
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,104);
}

/* =======================================
 *      89h
 * ======================================= */
void __bea_callspec__ test_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
    #endif
    (*pMyDisasm).Operand1.AccessMode = READ;
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,104);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ ud2_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ud2 ");
  #endif
  GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ vmread_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        GV.EVEX.tupletype = FULL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttpd2uqq ");
        #endif
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        GV.EVEX.tupletype = HALF;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttps2uqq ");
        #endif
        ArgsVEX_GEx(pMyDisasm, Arg2qword, Arg2_m128_xmm, Arg2_m256_ymm);
      }
    }
    else if (GV.VEX.pp == 2) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.EVEX.tupletype = TUPLE1_FIXED__32;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttss2usi ");
      #endif
      GV.MemDecoration = Arg2dword;
      GV.OperandSize = (GV.EVEX.W == 1) ? 64 : 32;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 3) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.EVEX.tupletype = TUPLE1_FIXED__64;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttsd2usi ");
      #endif
      GV.MemDecoration = (GV.EVEX.W == 1) ? Arg2qword : Arg2dword;
      GV.OperandSize = (GV.EVEX.W == 1) ? 64 : 32;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      if (GV.EVEX.W == 1) {
        GV.EVEX.tupletype = FULL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttpd2udq ");
        #endif
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        GV.EVEX.tupletype = FULL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttps2udq ");
        #endif
        ArgsVEX_GxEx(pMyDisasm);
      }
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmread ");
    #endif
    if (GV.Architecture == 64) GV.OperandSize = 64;
    EvGv(pMyDisasm);
    if (GV.Architecture == 64) GV.OperandSize = 32;
  }
}

/* =======================================
 *  0F 79
 * ======================================= */
void __bea_callspec__ vmwrite_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        GV.EVEX.tupletype = FULL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtpd2uqq ");
        #endif
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        GV.EVEX.tupletype = HALF;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtps2uqq ");
        #endif
        ArgsVEX_GEx(pMyDisasm, Arg2qword, Arg2_m128_xmm, Arg2_m256_ymm);
      }
    }
    else if (GV.VEX.pp == 2) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtss2usi ");
      #endif
      GV.EVEX.tupletype = TUPLE1_FIXED__32;
      GV.MemDecoration = Arg2dword;
      GV.OperandSize = (GV.EVEX.W == 1) ? 64 : 32;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 3) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtsd2usi ");
      #endif
      GV.EVEX.tupletype = TUPLE1_FIXED__64;
      GV.MemDecoration = (GV.EVEX.W == 1) ? Arg2qword : Arg2dword;
      GV.OperandSize = (GV.EVEX.W == 1) ? 64 : 32;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      if (GV.EVEX.W == 1) {
        GV.EVEX.tupletype = FULL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtpd2udq ");
        #endif
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        GV.EVEX.tupletype = FULL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtps2udq ");
        #endif
        ArgsVEX_GxEx(pMyDisasm);
      }
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmwrite ");
    #endif
    if (GV.Architecture == 64) GV.OperandSize = 64;
    GvEv(pMyDisasm);
    if (GV.Architecture == 64) GV.OperandSize = 32;
  }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ wbinvd_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "wbinvd ");
  #endif
  GV.EIP_++;
}

/* =======================================
 *      9Bh
 * ======================================= */
void __bea_callspec__ wait_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "wait ");
    #endif
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ wrmsr_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "wrmsr ");
    #endif
    GV.EIP_++;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
    (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
    (*pMyDisasm).Operand2.Registers.gpr = REG0+REG1+REG2;
    (*pMyDisasm).Operand2.OpSize = 32;
}


/* =======================================
 *      0fc0h
 * ======================================= */
void __bea_callspec__ xadd_EbGb(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xadd ");
  #endif
  EbGb(pMyDisasm);
  if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
    if ((*pMyDisasm).Operand1.OpType != MEMORY_TYPE) {
      GV.ERROR_OPCODE = UD_;
    }
  }
  (*pMyDisasm).Operand1.AccessMode = WRITE;
  (*pMyDisasm).Operand2.AccessMode = WRITE;
  FillFlags(pMyDisasm,110);
}

/* =======================================
 *      0fc1h
 * ======================================= */
void __bea_callspec__ xadd_EvGv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }

  if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
      (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
  }
  (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
  #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xadd ");
  #endif
  EvGv(pMyDisasm);
  if ((*pMyDisasm).Prefix.LockPrefix == InUsePrefix) {
    if ((*pMyDisasm).Operand1.OpType != MEMORY_TYPE) {
      GV.ERROR_OPCODE = UD_;
    }
  }
  (*pMyDisasm).Operand1.AccessMode = WRITE;
  (*pMyDisasm).Operand2.AccessMode = WRITE;
  FillFlags(pMyDisasm,110);
}

/* =======================================
 *      91h
 * ======================================= */
void __bea_callspec__ xchg_ecx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG1;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[1+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[1]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[1+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[1]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[1+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[1]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}


/* =======================================
 *      92h
 * ======================================= */
void __bea_callspec__ xchg_edx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG2;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[2+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[2]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[2+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[2]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[2+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[2]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}


/* =======================================
 *      93h
 * ======================================= */
void __bea_callspec__ xchg_ebx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG3;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[3+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[3]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[3+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[3]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[3+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[3]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}


/* =======================================
 *      94h
 * ======================================= */
void __bea_callspec__ xchg_esp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG4;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[4+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[4]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[4+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[4]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[4+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[4]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}


/* =======================================
 *      95h
 * ======================================= */
void __bea_callspec__ xchg_ebp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG5;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[5+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[5]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[5+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[5]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[5+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[5]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}


/* =======================================
 *      96h
 * ======================================= */
void __bea_callspec__ xchg_esi(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG6;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[6+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[6]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[6+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[6]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[6+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[6]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}


/* =======================================
 *      97h
 * ======================================= */
void __bea_callspec__ xchg_edi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
    (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG7;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers64Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[7+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers64Bits[7]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 64;
        (*pMyDisasm).Operand2.OpSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers32Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[7+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers32Bits[7]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 32;
        (*pMyDisasm).Operand2.OpSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, Registers16Bits[0]);
        #endif
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[7+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, Registers16Bits[7]);
            #endif
        }
        GV.EIP_++;
        (*pMyDisasm).Operand2.AccessMode = WRITE;
        (*pMyDisasm).Operand1.OpSize = 16;
        (*pMyDisasm).Operand2.OpSize = 16;
    }
}

/* =======================================
 *      0d7h
 * ======================================= */
void __bea_callspec__ xlat_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    if (GV.AddressSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xlatb ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 8;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG3;
        (*pMyDisasm).Operand2.OpSize = 64;
        GV.EIP_++;
    }
    else if (GV.AddressSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xlatb ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 8;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG3;
        (*pMyDisasm).Operand2.OpSize = 32;
        GV.EIP_++;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xlatb ");
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand1.Registers.gpr = REG0;
        (*pMyDisasm).Operand1.OpSize = 8;
        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = GENERAL_REG;
  (*pMyDisasm).Operand2.Registers.gpr = REG3;
        (*pMyDisasm).Operand2.OpSize = 16;
        GV.EIP_++;
    }
}


/* =======================================
 *      30h
 * ======================================= */
void __bea_callspec__ xor_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xor ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,113);
}

/* =======================================
 *      31h
 * ======================================= */
void __bea_callspec__ xor_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xor ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,113);
}

/* =======================================
 *      32h
 * ======================================= */
void __bea_callspec__ xor_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xor ");
    #endif
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,113);
}

/* =======================================
 *      33h
 * ======================================= */
void __bea_callspec__ xor_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xor ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,113);
}

/* =======================================
 *      34h
 * ======================================= */
void __bea_callspec__ xor_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xor ");
    #endif
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,113);
}

/* =======================================
 *      35h
 * ======================================= */
void __bea_callspec__ xor_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xor ");
    #endif
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,113);
}


/* =======================================
 *      86h
 * ======================================= */
void __bea_callspec__ xchg_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,113);
    (*pMyDisasm).Operand2.AccessMode = WRITE;
}

/* =======================================
 *      87h
 * ======================================= */
void __bea_callspec__ xchg_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xchg ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,113);
    (*pMyDisasm).Operand2.AccessMode = WRITE;
}


/* ====================================================================
*      0x 0f 58
* ==================================================================== */
void __bea_callspec__ addps_VW(PDISASM pMyDisasm)
{
  /* ========= 0xf2 */
  if (GV.PrefRepne == 1) {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaddsd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
      if (GV.REX.W_ == 0x1) GV.OperandSize = 64;
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg3qword;
      GyEy(pMyDisasm);
    }
    else {
      (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsd ");
      #endif
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg2qword;
      GxEx(pMyDisasm);
    }
  }
   /* ========= 0xf3 */
  else if (GV.PrefRepe == 1) {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaddss ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
      if (GV.REX.W_ == 0x1) GV.OperandSize = 64;
      GV.Register_ = SSE_REG;
      GyEy(pMyDisasm);
      GV.MemDecoration = Arg3dword;
    }
    else {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2dword;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addss ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
  /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaddpd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      if (GV.REX.W_ == 0x1) GV.OperandSize = 64;
      ArgsVEX(pMyDisasm);
    }
    else {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128d_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addpd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
  else {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaddps ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      if (GV.REX.W_ == 0x1) GV.OperandSize = 64;
      ArgsVEX(pMyDisasm);
    }
     else {
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
     }
  }
}

/* ====================================================================
*      0x 0f d0
* ==================================================================== */
void __bea_callspec__ addsubpd_(PDISASM pMyDisasm)
{
   /* ========= 0xf2 */
   if (GV.EVEX.state == InUsePrefix) {
     FailDecode(pMyDisasm);
   }
   else if (GV.PrefRepne == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+SIMD_FP_PACKED;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaddsubps ");
           #endif
           if (GV.VEX.opcode == 0xc4) {
             /* using VEX3Bytes */
             if (GV.REX.W_ == 0x1) {
              GV.OperandSize = 64;
             }
           }
           if (GV.VEX.L == 0) {
            GV.Register_ = SSE_REG;
            GyEy(pMyDisasm);
            GV.MemDecoration = Arg3_m128_xmm;
           }
           else {
               GV.Register_ = AVX_REG;
               GyEy(pMyDisasm);
               GV.MemDecoration = Arg3_m256_ymm;
           }
       }
      else {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2_m128_xmm;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsubps ");
        #endif
        GV.Register_ = SSE_REG;
        GxEx(pMyDisasm);
        (*pMyDisasm).Operand2.OpSize = 128;
      }
   }

   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       if (GV.VEX.state == InUsePrefix) {
          (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+SIMD_FP_PACKED;
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaddsubpd ");
          #endif
          if (GV.VEX.opcode == 0xc4) {
            /* using VEX3Bytes */
            if (GV.REX.W_ == 0x1) {
              GV.OperandSize = 64;
            }
          }
          if (GV.VEX.L == 0) {
            GV.Register_ = SSE_REG;
            GyEy(pMyDisasm);
            GV.MemDecoration = Arg3_m128d_xmm;
          }
          else {
            GV.Register_ = AVX_REG;
            GyEy(pMyDisasm);
            GV.MemDecoration = Arg3_m256d_ymm;
          }
           /* FillFlags(pMyDisasm,125); */
       }
       else {
           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128d_xmm;
           (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsubpd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

           (*pMyDisasm).Operand2.OpSize = 128;
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}


/* ====================================================================
*      0x 0f 55
* ==================================================================== */
void __bea_callspec__ andnps_VW(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {

       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vandnpd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if (GV.VEX.opcode == 0xc4) {
               /* using VEX3Bytes */
               if (GV.REX.W_ == 0x1) {
                   GV.OperandSize = 64;
               }
           }
           ArgsVEX(pMyDisasm);

       }
       else {
           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128d_xmm;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andnpd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
   else {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vandnps ");
           #endif

           if (GV.VEX.opcode == 0xc4) {
               /* using VEX3Bytes */
               if (GV.REX.W_ == 0x1) {
                   GV.OperandSize = 64;
               }
           }
           ArgsVEX(pMyDisasm);
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
       }
       else {
           GV.MemDecoration = Arg2_m128_xmm;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andnps ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
}


/* ====================================================================
*      0x 0f 54
* ==================================================================== */
void __bea_callspec__ andps_VW(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {

     if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vandpd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      if (GV.REX.W_ == 0x1) GV.OperandSize = 64;
      ArgsVEX(pMyDisasm);
     }
     else {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128d_xmm;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andpd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

     }
   }
   else {
       if (GV.VEX.state == InUsePrefix) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vandps ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         if (GV.REX.W_ == 0x1) GV.OperandSize = 64;
         ArgsVEX(pMyDisasm);
       }
       else {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andps ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
}

/* ====================================================================
*      0x 0f 3a 00
* ==================================================================== */
void __bea_callspec__ vpermq_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (
        ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) ||
        ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 1))) {
          verifyVEXvvvv(pMyDisasm);
          if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
          if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermq ");
          #endif
          ArgsVEX_GxEx(pMyDisasm);
          getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 01
* ==================================================================== */
void __bea_callspec__ vpermpd(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (
        ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) ||
        ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 1))) {
          verifyVEXvvvv(pMyDisasm);
          if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
          if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermpd ");
          #endif
          ArgsVEX_GxEx(pMyDisasm);
          getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 02
* ==================================================================== */
void __bea_callspec__ vpblendd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendd ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 03
* ==================================================================== */
void __bea_callspec__ valignd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "valignq ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "valignd ");
        #endif
      }
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }

  }
  else {
    FailDecode(pMyDisasm);
  }

}
/* ====================================================================
*      0x 0f 3a 0d
* ==================================================================== */
void __bea_callspec__ blendpd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += PACKED_BLENDING_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vblendpd ");
      #endif
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg2_m128_xmm;
        GxEx(pMyDisasm);
      }
      else {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg2_m256_ymm;
        GxEx(pMyDisasm);
      }
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendpd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 3a cc
* ==================================================================== */
void __bea_callspec__ sha1rnds4_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SHA_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sha1rnds4 ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 0c
* ==================================================================== */
void __bea_callspec__ blendps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + PACKED_BLENDING_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vblendps ");
      #endif
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GxEx(pMyDisasm);
        GV.MemDecoration = Arg2_m128_xmm;
      }
      else {
        GV.Register_ = AVX_REG;
        GxEx(pMyDisasm);
        GV.MemDecoration = Arg2_m256_ymm;
      }
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
  }
  else {
     FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 15 / 0x 0f 3a 4b
* ==================================================================== */
void __bea_callspec__ blendvpd_(PDISASM pMyDisasm)
{
 UInt8 Imm8;
 if (GV.EVEX.state == InUsePrefix) {
   if (GV.VEX.pp == 1) {
     if (GV.EVEX.W == 1) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vprolvq ");
       #endif
     }
     else {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vprolvd ");
       #endif
     }
     GV.EVEX.tupletype = FULL;
     ArgsVEX(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     if (GV.EVEX.W == 0) {
       if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovusqd ");
       #endif
       GV.EVEX.tupletype = HALF_MEM;
       ArgsVEX_ExG(pMyDisasm, Arg1dword, Arg1qword, Arg1_m128_xmm, SSE_REG, SSE_REG, SSE_REG);
     }
     else {
       FailDecode(pMyDisasm);
     }
   }
   else {
     FailDecode(pMyDisasm);
   }
 }

   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     if (GV.VEX.state == InUsePrefix) {
       GV.ERROR_OPCODE = UD_;
       (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vblendvpd ");
       #endif
      if (GV.REX.W_ == 0x1) GV.ERROR_OPCODE = UD_;
       if (GV.VEX.L == 0) {
         GV.Register_ = SSE_REG;
         GV.MemDecoration = Arg3_m128_xmm;
         GyEy(pMyDisasm);
         GV.EIP_++;
         if (!Security(0, pMyDisasm)) return;
         Imm8 = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
         fillRegister((Imm8 >> 4) & 0xF, &(*pMyDisasm).Operand4, pMyDisasm);
       }
       else {
         GV.Register_ = AVX_REG;
         GV.MemDecoration = Arg3_m256_ymm;
         GyEy(pMyDisasm);
         GV.EIP_++;
         if (!Security(0, pMyDisasm)) return;
         Imm8 = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
         fillRegister((Imm8 >> 4) & 0xF, &(*pMyDisasm).Operand4, pMyDisasm);
       }
     }
     else {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128d_xmm;
       (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendvpd ");
       #endif
       GV.Register_ = SSE_REG;
       (*pMyDisasm).Operand3.AccessMode = READ;
       (*pMyDisasm).Operand3.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand3.Registers.type = SSE_REG;
  (*pMyDisasm).Operand3.Registers.xmm = REG0;
       (*pMyDisasm).Operand3.OpSize = 128;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((char*) (*pMyDisasm).Operand3.OpMnemonic, RegistersSSE[0]);
       #endif
       GxEx(pMyDisasm);

     }
   }
   else {
       FailDecode(pMyDisasm);
   }

}


/* ====================================================================
*      0x 0f 38 14
* ==================================================================== */
void __bea_callspec__ blendvps_(PDISASM pMyDisasm)
{
  UInt8 Imm8;
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vprorvq ");
        #endif
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vprorvd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 0) {
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovusqw ");
        #endif
        GV.EVEX.tupletype = HALF_MEM;
        ArgsVEX_ExG(pMyDisasm, Arg1dword, Arg1qword, Arg1_m128_xmm, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    if (GV.VEX.state == InUsePrefix) {
      GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vblendvps ");
      #endif
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
        GyEy(pMyDisasm);
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        Imm8 = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        fillRegister((Imm8 >> 4) & 0xF, &(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
        GyEy(pMyDisasm);
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        Imm8 = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        fillRegister((Imm8 >> 4) & 0xF, &(*pMyDisasm).Operand4, pMyDisasm);
      }
    }
    else {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendvps ");
      #endif
      GV.Register_ = SSE_REG;
      (*pMyDisasm).Operand3.AccessMode = READ;
      (*pMyDisasm).Operand3.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand3.Registers.type = SSE_REG;
  (*pMyDisasm).Operand3.Registers.xmm = REG0;
      (*pMyDisasm).Operand3.OpSize = 128;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((char*) (*pMyDisasm).Operand3.OpMnemonic, RegistersSSE[0]);
      #endif
      GxEx(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 3f
* ==================================================================== */
void __bea_callspec__ vpcmpccb(PDISASM pMyDisasm)
{
  UInt8 Imm8;

  char pseudoOpcodes_ud[8][16] = {
    "vpcmpeqb ",
    "vpcmpltb ",
    "vpcmpleb ",
    "vpcmpfalseb ",
    "vpcmpneqb ",
    "vpcmpnltb ",
    "vpcmpnleb ",
    "vpcmptrueb "
  };
  char pseudoOpcodes_uq[8][16] = {
    "vpcmpeqw ",
    "vpcmpltw ",
    "vpcmplew ",
    "vpcmpfalsew ",
    "vpcmpneqw ",
    "vpcmpnltw ",
    "vpcmpnlew ",
    "vpcmptruew "
  };
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      GV.EVEX.tupletype = FULL;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_ud[Imm8]);
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_uq[Imm8]);
        #endif
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 3e
* ==================================================================== */
void __bea_callspec__ vpcmpccub(PDISASM pMyDisasm)
{
  UInt8 Imm8;

  char pseudoOpcodes_ud[8][16] = {
    "vpcmpequb ",
    "vpcmpltub ",
    "vpcmpleub ",
    "vpcmpfalseub ",
    "vpcmpnequb ",
    "vpcmpnltub ",
    "vpcmpnleub ",
    "vpcmptrueub "
  };
  char pseudoOpcodes_uq[8][16] = {
    "vpcmpequw ",
    "vpcmpltuw ",
    "vpcmpleuw ",
    "vpcmpfalseuw ",
    "vpcmpnequw ",
    "vpcmpnltuw ",
    "vpcmpnleuw ",
    "vpcmptrueuw "
  };
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      GV.EVEX.tupletype = FULL;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_ud[Imm8]);
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_uq[Imm8]);
        #endif
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 1f
* ==================================================================== */
void __bea_callspec__ vpcmpccd(PDISASM pMyDisasm)
{
  UInt8 Imm8;

  char pseudoOpcodes_ud[8][16] = {
    "vpcmpeqd ",
    "vpcmpltd ",
    "vpcmpled ",
    "vpcmpfalsed ",
    "vpcmpneqd ",
    "vpcmpnltd ",
    "vpcmpnled ",
    "vpcmptrued "
  };
  char pseudoOpcodes_uq[8][16] = {
    "vpcmpeqq ",
    "vpcmpltq ",
    "vpcmpleq ",
    "vpcmpfalseq ",
    "vpcmpneqq ",
    "vpcmpnltq ",
    "vpcmpnleq ",
    "vpcmptrueq "
  };
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      GV.EVEX.tupletype = FULL;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_ud[Imm8]);
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_uq[Imm8]);
        #endif
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 1e
* ==================================================================== */
void __bea_callspec__ vpcmpccud(PDISASM pMyDisasm)
{
  UInt8 Imm8;

  char pseudoOpcodes_ud[8][16] = {
    "vpcmpequd ",
    "vpcmpltud ",
    "vpcmpleud ",
    "vpcmpfalseud ",
    "vpcmpnequd ",
    "vpcmpnltud ",
    "vpcmpnleud ",
    "vpcmptrueud "
  };
  char pseudoOpcodes_uq[8][16] = {
    "vpcmpequq ",
    "vpcmpltuq ",
    "vpcmpleuq ",
    "vpcmpfalseuq ",
    "vpcmpnequq ",
    "vpcmpnltuq ",
    "vpcmpnleuq ",
    "vpcmptrueuq "
  };
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      GV.EVEX.tupletype = FULL;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Operand1.AccessMode = READ;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_ud[Imm8]);
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_uq[Imm8]);
        #endif
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f c2
* ==================================================================== */
void __bea_callspec__ cmpps_VW(PDISASM pMyDisasm)
{
   UInt8 Imm8;
   char pseudoOpcodes_sd[0x20][16] = {
       "vcmpeqsd ",
       "vcmpltsd ",
       "vcmplesd ",
       "vcmpunordsd ",
       "vcmpneqsd ",
       "vcmpnltsd ",
       "vcmpnlesd ",
       "vcmpordsd ",
       "vcmpeq_uqsd ",
       "vcmpngesd ",
       "vcmpngtsd ",
       "vcmpfalsesd ",
       "vcmpneq_oqsd ",
       "vcmpgesd ",
       "vcmpgtsd ",
       "vcmptruesd ",
       "vcmpeq_ossd ",
       "vcmplt_oqsd ",
       "vcmple_oqsd ",
       "vcmpunord_ssd ",
       "vcmpneq_ussd ",
       "vcmpnlt_uqsd ",
       "vcmpnle_uqsd ",
       "vcmpord_ssd ",
       "vcmpeq_ussd ",
       "vcmpnge_uqsd ",
       "vcmpngt_uqsd ",
       "vcmpfalse_ossd ",
       "vcmpneq_ossd ",
       "vcmpge_oqsd ",
       "vcmpgt_oqsd ",
       "vcmptrue_ussd "
   };

   char pseudoOpcodes_ss[0x20][16] = {
       "vcmpeqss ",
       "vcmpltss ",
       "vcmpless ",
       "vcmpunordss ",
       "vcmpneqss ",
       "vcmpnltss ",
       "vcmpnless ",
       "vcmpordss ",
       "vcmpeq_uqss ",
       "vcmpngess ",
       "vcmpngtss ",
       "vcmpfalsess ",
       "vcmpneq_oqss ",
       "vcmpgess ",
       "vcmpgtss ",
       "vcmptruess ",
       "vcmpeq_osss ",
       "vcmplt_oqss ",
       "vcmple_oqss ",
       "vcmpunord_sss ",
       "vcmpneq_usss ",
       "vcmpnlt_uqss ",
       "vcmpnle_uqss ",
       "vcmpord_sss ",
       "vcmpeq_usss ",
       "vcmpnge_uqss ",
       "vcmpngt_uqss ",
       "vcmpfalse_osss ",
       "vcmpneq_osss ",
       "vcmpge_oqss ",
       "vcmpgt_oqss ",
       "vcmptrue_usss "
   };

   char pseudoOpcodes_pd[0x20][16] = {
       "vcmpeqpd ",
       "vcmpltpd ",
       "vcmplepd ",
       "vcmpunordpd ",
       "vcmpneqpd ",
       "vcmpnltpd ",
       "vcmpnlepd ",
       "vcmpordpd ",
       "vcmpeq_uqpd ",
       "vcmpngepd ",
       "vcmpngtpd ",
       "vcmpfalsepd ",
       "vcmpneq_oqpd ",
       "vcmpgepd ",
       "vcmpgtpd ",
       "vcmptruepd ",
       "vcmpeq_ospd ",
       "vcmplt_oqpd ",
       "vcmple_oqpd ",
       "vcmpunord_spd ",
       "vcmpneq_uspd ",
       "vcmpnlt_uqpd ",
       "vcmpnle_uqpd ",
       "vcmpord_spd ",
       "vcmpeq_uspd ",
       "vcmpnge_uqpd ",
       "vcmpngt_uqpd ",
       "vcmpfalse_ospd ",
       "vcmpneq_ospd ",
       "vcmpge_oqpd ",
       "vcmpgt_oqpd ",
       "vcmptrue_uspd "
   };

   char pseudoOpcodes_ps[0x20][16] = {
       "vcmpeqps ",
       "vcmpltps ",
       "vcmpleps ",
       "vcmpunordps ",
       "vcmpneqps ",
       "vcmpnltps ",
       "vcmpnleps ",
       "vcmpordps ",
       "vcmpeq_uqps ",
       "vcmpngeps ",
       "vcmpngtps ",
       "vcmpfalseps ",
       "vcmpneq_oqps ",
       "vcmpgeps ",
       "vcmpgtps ",
       "vcmptrueps ",
       "vcmpeq_osps ",
       "vcmplt_oqps ",
       "vcmple_oqps ",
       "vcmpunord_sps ",
       "vcmpneq_usps ",
       "vcmpnlt_uqps ",
       "vcmpnle_uqps ",
       "vcmpord_sps ",
       "vcmpeq_usps ",
       "vcmpnge_uqps ",
       "vcmpngt_uqps ",
       "vcmpfalse_osps ",
       "vcmpneq_osps ",
       "vcmpge_oqps ",
       "vcmpgt_oqps ",
       "vcmptrue_usps "
   };


   /* ========= 0xf2 */
   GV.ImmediatSize = 8;
   if (GV.PrefRepne == 1) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 0)
     ) {
       FailDecode(pMyDisasm);
     }
     else if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + COMPARISON_INSTRUCTION;
           if (GV.EVEX.state == InUsePrefix) {
             ArgsVEX_CMPPS(pMyDisasm);
           }
           else {
             ArgsVEX(pMyDisasm);
           }
           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x1F;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_sd[Imm8]);
           #endif
       }
       else {

           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2qword;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;

           if (Imm8 == 0x0) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpeqsd ");
               #endif
           }
           else if (Imm8 == 0x1) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpltsd ");
               #endif
           }
           else if (Imm8 == 0x2) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmplesd ");
               #endif
           }
           else if (Imm8 == 0x3) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpunordsd ");
               #endif
           }
           else if (Imm8 == 0x4) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpneqsd ");
               #endif
           }
           else if (Imm8 == 0x5) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnltsd ");
               #endif
           }
           else if (Imm8 == 0x6) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnlesd ");
               #endif
           }
           else if (Imm8 == 0x7) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpordsd ");
               #endif
           }
       }


   }
   /* ========== 0xf3 */
   else if (GV.PrefRepe == 1) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 1)
     ) {
       FailDecode(pMyDisasm);
     }
     else if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + COMPARISON_INSTRUCTION;
           if (GV.EVEX.state == InUsePrefix) {
             ArgsVEX_CMPPS(pMyDisasm);
           }
           else {
             ArgsVEX(pMyDisasm);
           }
           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x1F;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_ss[Imm8]);
           #endif
       }
       else {

           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2dword;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;

           if (Imm8 == 0x0) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpeqss ");
               #endif
           }
           else if (Imm8 == 0x1) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpltss ");
               #endif
           }
           else if (Imm8 == 0x2) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpless ");
               #endif
           }
           else if (Imm8 == 0x3) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpunordss ");
               #endif
           }
           else if (Imm8 == 0x4) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpneqss ");
               #endif
           }
           else if (Imm8 == 0x5) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnltss ");
               #endif
           }
           else if (Imm8 == 0x6) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnless ");
               #endif
           }
           else if (Imm8 == 0x7) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpordss ");
               #endif
           }
       }

   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 0)
     ) {
       FailDecode(pMyDisasm);
     }
     else if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + COMPARISON_INSTRUCTION;
           if (GV.EVEX.state == InUsePrefix) {
             ArgsVEX_CMPPS(pMyDisasm);
           }
           else {
             ArgsVEX(pMyDisasm);
           }

           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x1F;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_pd[Imm8]);
           #endif
       }
       else {
           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128_xmm;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;
           if (Imm8 == 0x0) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpeqpd ");
               #endif
           }
           else if (Imm8 == 0x1) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpltpd ");
               #endif
           }
           else if (Imm8 == 0x2) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmplepd ");
               #endif
           }
           else if (Imm8 == 0x3) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpunordpd ");
               #endif
           }
           else if (Imm8 == 0x4) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpneqpd ");
               #endif
           }
           else if (Imm8 == 0x5) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnltpd ");
               #endif
           }
           else if (Imm8 == 0x6) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnlepd ");
               #endif
           }
           else if (Imm8 == 0x7) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpordpd ");
               #endif
           }
       }
   }
   else {
      if (
        (GV.EVEX.state == InUsePrefix) &&
        (GV.EVEX.W == 1)
      ) {
        FailDecode(pMyDisasm);
      }
      else if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + COMPARISON_INSTRUCTION;
           if (GV.EVEX.state == InUsePrefix) {
             ArgsVEX_CMPPS(pMyDisasm);
           }
           else {
             ArgsVEX(pMyDisasm);
           }
           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x1F;

           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, pseudoOpcodes_ps[Imm8]);
           #endif
       }
       else {

           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128_xmm;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
           (*pMyDisasm).Operand1.AccessMode = READ;
           getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
           Imm8 = (*pMyDisasm).Instruction.Immediat & 0x7;

           if (Imm8 == 0x0) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpeqps ");
               #endif
           }
           else if (Imm8 == 0x1) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpltps ");
               #endif
           }
           else if (Imm8 == 0x2) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpleps ");
               #endif
           }
           else if (Imm8 == 0x3) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpunordps ");
               #endif
           }
           else if (Imm8 == 0x4) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpneqps ");
               #endif
           }
           else if (Imm8 == 0x5) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnltps ");
               #endif
           }
           else if (Imm8 == 0x6) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpnleps ");
               #endif
           }
           else if (Imm8 == 0x7) {
               #ifndef BEA_LIGHT_DISASSEMBLY
                  (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpordps ");
               #endif
           }
       }
   }


}


/* ====================================================================
*      0x 0f 38 f0
* ==================================================================== */
void __bea_callspec__ crc32_GvEb(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
  if (GV.PrefRepne == 1) {
    /* ========= 0xf2 */
    (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
    (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "crc32 ");
    #endif
    if (GV.OperandSize == 64) {
      GV.MemDecoration = Arg2byte;
      GV.OperandSize = 8;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.OperandSize = 64;
    }
    else if (GV.OperandSize == 32) {
      GV.MemDecoration = Arg2byte;
      GV.OperandSize = 8;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.OperandSize = 32;
    }
    else {
      GV.MemDecoration = Arg2byte;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
    }

    if (GV.OperandSize == 16) {
      GV.OperandSize = 32;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.OperandSize = 16;
    }
    else {
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
    }
  else {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) { FailDecode(pMyDisasm); return; }
    if (GV.PrefRepe == 1) GV.ERROR_OPCODE = UD_;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movbe ");
    #endif
    GvEv(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 f1
* ==================================================================== */
void __bea_callspec__ crc32_GvEv(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
   /* ========= 0xf2 */
  if (GV.PrefRepne == 1) {
    (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
    (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "crc32 ");
    #endif

    if (GV.OperandSize == 64) {
      GV.MemDecoration = Arg2qword;
    }
    else if (GV.OperandSize == 32) {
      GV.MemDecoration = Arg2dword;
    }
    else {
      GV.MemDecoration = Arg2word;
    }
    MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

    if (GV.OperandSize == 16) {
      GV.OperandSize = 32;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.OperandSize = 16;
    }
    else {
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
   }
  else {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) { FailDecode(pMyDisasm); return; }
    if (GV.PrefRepe == 1) GV.ERROR_OPCODE = UD_;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movbe ");
    #endif
    EvGv(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 2f
* ==================================================================== */
void __bea_callspec__ comiss_VW(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 1)
     ) {
       FailDecode(pMyDisasm);
       return;
     }
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcomiss ");
     #endif
     GV.MemDecoration = Arg2dword;
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
   }
   else if (GV.VEX.pp == 1) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 0)
     ) {
       FailDecode(pMyDisasm);
       return;
     }
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcomisd ");
     #endif
     GV.MemDecoration = Arg2qword;
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "comisd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
   else {
       GV.MemDecoration = Arg2dword;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "comiss ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
 }
}

/* ====================================================================
*      0x 0f 5a
* ==================================================================== */
void __bea_callspec__ cvtps2pd_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 0x1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtpd2ps ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else if (GV.VEX.pp == 0x2) {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
        FailDecode(pMyDisasm);
        return;
      }
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtss2sd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
      }
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg3dword;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = 0;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 0x3) {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0)) {
        FailDecode(pMyDisasm);
        return;
      }
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtsd2ss ");
      #endif
      if (GV.EVEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
      }
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg3qword;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = 0;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
        FailDecode(pMyDisasm);
        return;
      }
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtps2pd ");
      #endif
      if (GV.VEX.L == 0) {
        (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg2qword;
        GxEx(pMyDisasm);
      }
      else if (GV.VEX.L == 0x1) {
        (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
        GV.MemDecoration = Arg2_m128_xmm;
        GV.Register_ = SSE_REG;
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        GV.Register_ = AVX_REG;
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else if (GV.EVEX.LL == 0x2) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.EVEX.tupletype = HALF;
        GV.MemDecoration = Arg2_m256_ymm;
        GV.Register_ = AVX_REG;
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        GV.Register_ = AVX512_REG;
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
    }
  }
  else {
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
      (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2qword;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsd2ss ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2dword;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtss2sd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2ps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2qword;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2pd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f 7b
* ==================================================================== */
void __bea_callspec__ vcvtps2qq_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtpd2qq ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtps2qq ");
        #endif
        ArgsVEX_GEx(pMyDisasm, Arg2qword, Arg2_m128_xmm, Arg2_m256_ymm);
      }
    }
    else if (GV.VEX.pp == 2) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtusi2ss ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
      GV.MemDecoration = (GV.EVEX.W == 0) ? Arg3dword : Arg3qword;
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      GV.Register_ = SSE_REG;
      GyEy(pMyDisasm);
    }
    else if (GV.VEX.pp == 3) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtusi2sd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
      GV.MemDecoration = (GV.EVEX.W == 0) ? Arg3dword : Arg3qword;
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      GV.Register_ = SSE_REG;
      GyEy(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 7a
* ==================================================================== */
void __bea_callspec__ vcvttps2qq_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttpd2qq ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttps2qq ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF;
        ArgsVEX_GEx(pMyDisasm, Arg2qword, Arg2_m128_xmm, Arg2_m256_ymm);
      }
    }
    else if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtuqq2pd ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtudq2pd ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF;
        ArgsVEX_GEx(pMyDisasm, Arg2qword, Arg2_m128_xmm, Arg2_m256_ymm);
      }
    }
    else if (GV.VEX.pp == 3) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtuqq2ps ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
        ArgsVEX_GxE(pMyDisasm, SSE_REG, SSE_REG, AVX_REG);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtudq2ps ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 5b
* ==================================================================== */
void __bea_callspec__ cvtdq2ps_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtps2dq ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      verifyVEXvvvv(pMyDisasm);
      ArgsVEX_GxEx(pMyDisasm);
    }
    else if (GV.VEX.pp == 2) {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
        FailDecode(pMyDisasm);
        return;
      }
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttps2dq ");
      #endif
      verifyVEXvvvv(pMyDisasm);
      ArgsVEX_GxEx(pMyDisasm);
    }
    else if (GV.VEX.pp == 0) {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
        FailDecode(pMyDisasm);
        return;
      }
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtdq2ps ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      verifyVEXvvvv(pMyDisasm);
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0xf3 */
    if (GV.PrefRepe == 1) {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttps2dq ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2dq ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtdq2ps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 2a
* ==================================================================== */
void __bea_callspec__ cvtpi2ps_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     FailDecode(pMyDisasm);
   }
   else if (GV.VEX.pp == 1) {
     FailDecode(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtsi2ss ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
     if (
       ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
       ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
     ){
       GV.MemDecoration = Arg3dword;
     }
     else {
       GV.MemDecoration = Arg3qword;
     }
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     GV.Register_ = SSE_REG;
     GyEy(pMyDisasm);


   }
   else {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtsi2sd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
     if (
       ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
       ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
     ){
       GV.MemDecoration = Arg3dword;
     }
     else {
       GV.MemDecoration = Arg3qword;
     }
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     GV.Register_ = SSE_REG;
     GyEy(pMyDisasm);


   }
 }
 else {
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
       (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsi2sd ");
       #endif
       if (GV.REX.W_ == 1) {
           GV.MemDecoration = Arg2qword;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = SSE_REG;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
       else {
           GV.MemDecoration = Arg2dword;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = SSE_REG;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
   }
   /* ========== 0xf3 */
   else if (GV.PrefRepe == 1) {
       (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsi2ss ");
       #endif
       if (GV.REX.W_ == 1) {
           GV.MemDecoration = Arg2qword;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = SSE_REG;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
       else {
           GV.MemDecoration = Arg2dword;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = SSE_REG;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpi2pd ");
       #endif
       GV.MemDecoration = Arg2qword;
       GV.Register_ = MMX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = SSE_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_+= GV.DECALAGE_EIP+2;
   }
   else {
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpi2ps ");
       #endif
       GV.MemDecoration = Arg2qword;
       GV.Register_ = MMX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = SSE_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_+= GV.DECALAGE_EIP+2;
   }
 }
}


/* ====================================================================
*      0x 0f 2d
* ==================================================================== */
void __bea_callspec__ cvtps2pi_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     FailDecode(pMyDisasm);
   }
   else if (GV.VEX.pp == 1) {
     FailDecode(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     (*pMyDisasm).Instruction.Category += CONVERSION_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtss2si ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_FIXED__32;
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
         GV.MemDecoration = Arg2dword;
         GV.Register_ = SSE_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         GV.OperandSize = 32;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_+= GV.DECALAGE_EIP+2;
     }
     else {
       GV.MemDecoration = Arg2dword;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       GV.OperandSize = 64;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_+= GV.DECALAGE_EIP+2;

     }
   }
   else {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtsd2si ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_FIXED__64;
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     (*pMyDisasm).Instruction.Category += CONVERSION_INSTRUCTION;
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
         GV.MemDecoration = Arg2qword;
         GV.Register_ = SSE_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         GV.OperandSize = 32;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_+= GV.DECALAGE_EIP+2;
     }
     else {
       GV.MemDecoration = Arg2qword;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       GV.OperandSize = 64;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_+= GV.DECALAGE_EIP+2;

     }
   }
 }
 else {

   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
       (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsd2si ");
       #endif
       if (GV.REX.W_ == 1) {
           GV.MemDecoration = Arg2qword;
           GV.Register_ = SSE_REG;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = 0;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
       else {
           GV.MemDecoration = Arg2qword;
           GV.Register_ = SSE_REG;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = 0;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
   }
   /* ========== 0xf3 */
   else if (GV.PrefRepe == 1) {
       (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtss2si ");
       #endif
       if (GV.REX.W_ == 1) {
           GV.MemDecoration = Arg2dword;
           GV.Register_ = SSE_REG;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = 0;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
       else {
           GV.MemDecoration = Arg2dword;
           GV.Register_ = SSE_REG;
           MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
           GV.Register_ = 0;
           Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
           GV.EIP_+= GV.DECALAGE_EIP+2;
       }
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2pi ");
       #endif
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = MMX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_+= GV.DECALAGE_EIP+2;
   }
   else {
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2pi ");
       #endif
       GV.MemDecoration = Arg2qword;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = MMX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_+= GV.DECALAGE_EIP+2;
   }
 }
}


/* ====================================================================
*      0x 0f 2c
* ==================================================================== */
void __bea_callspec__ cvttps2pi_(PDISASM pMyDisasm)
{

 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     FailDecode(pMyDisasm);
   }
   else if (GV.VEX.pp == 1) {
     FailDecode(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttss2si ");
     #endif
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_FIXED__32;
         GV.MemDecoration = Arg2dword;
         GV.Register_ = SSE_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         GV.OperandSize = 32;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_+= GV.DECALAGE_EIP+2;
     }
     else {
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_FIXED__64;
       GV.MemDecoration = Arg2dword;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       GV.OperandSize = 64;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_+= GV.DECALAGE_EIP+2;

     }
   }
   else {
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttsd2si ");
     #endif
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_FIXED__32;
         GV.MemDecoration = Arg2qword;
         GV.Register_ = SSE_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         GV.OperandSize = 32;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_+= GV.DECALAGE_EIP+2;
     }
     else {
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_FIXED__64;
       GV.MemDecoration = Arg2qword;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       GV.OperandSize = 64;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_+= GV.DECALAGE_EIP+2;

     }
   }
 }
 else {
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
     (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttsd2si ");
     #endif
     if (GV.REX.W_ == 1) {
       GV.MemDecoration = Arg2qword;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_+= GV.DECALAGE_EIP+2;
     }
     else {
       GV.MemDecoration = Arg2qword;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_+= GV.DECALAGE_EIP+2;
     }
   }
   /* ========== 0xf3 */
   else if (GV.PrefRepe == 1) {
     (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttss2si ");
     #endif
     GV.MemDecoration = Arg2dword;
     GV.Register_ = SSE_REG;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
     GV.Register_ = 0;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
     GV.EIP_+= GV.DECALAGE_EIP+2;
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttpd2pi ");
     #endif
     GV.MemDecoration = Arg2_m128_xmm;
     GV.Register_ = SSE_REG;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
     GV.Register_ = MMX_REG;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

     GV.EIP_+= GV.DECALAGE_EIP+2;
   }
   else {
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttps2pi ");
     #endif
     GV.MemDecoration = Arg2qword;
     GV.Register_ = SSE_REG;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

     GV.Register_ = MMX_REG;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

     GV.EIP_+= GV.DECALAGE_EIP+2;
    }
  }
}


/* ====================================================================
*      0x 0f e6
* ==================================================================== */
void __bea_callspec__ cvtpd2dq_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 0) {
      FailDecode(pMyDisasm);
      return;
    }
    if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
    if (GV.VEX.pp == 1) {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0)) { FailDecode(pMyDisasm); return; }
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvttpd2dq ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX_GxE(pMyDisasm, SSE_REG, SSE_REG, AVX_REG);
    }
    else if (GV.VEX.pp == 2) {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) { FailDecode(pMyDisasm); return; }
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtdq2pd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) {
        GV.EVEX.tupletype = HALF;
        ArgsVEX_GEx(pMyDisasm, Arg2_m128_xmm, Arg2_m128_xmm, Arg2_m256_ymm);
      }
      else {
        ArgsVEX_GEx(pMyDisasm, Arg2qword, Arg2_m128_xmm, Arg2_m256_ymm);
      }

    }
    else {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0)) { FailDecode(pMyDisasm); return; }
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtpd2dq ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX_GxE(pMyDisasm, SSE_REG, SSE_REG, AVX_REG);
    }
  }
  else {
    /* ========== 0xf2 */
     if (GV.PrefRepne == 1) {
       (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2dq ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);
     }
     /* ========== 0xf3 */
     else if (GV.PrefRepe == 1) {
       (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtdq2pd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);
     }
     /* ========== 0x66 */
     else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttpd2dq ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);
     }
     else {
       FailDecode(pMyDisasm);
     }
  }

}


/* ====================================================================
*      0x 0f 3a 41
* ==================================================================== */
void __bea_callspec__ dppd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vdppd ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dppd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f 3a 40
* ==================================================================== */
void __bea_callspec__ dpps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vdpps ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dpps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }

  }

}

/* ====================================================================
*      0x 0f 3a 17
* ==================================================================== */
void __bea_callspec__ extractps_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg1dword;
      if (GV.EVEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION+INSERTION_EXTRACTION;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+INSERTION_EXTRACTION;
      }

      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextractps ");
      #endif
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_+= GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg1dword;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "extractps ");
      #endif
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_+= GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 7c
* ==================================================================== */
void __bea_callspec__ haddpd_VW(PDISASM pMyDisasm)
{

 if (GV.VEX.state == InUsePrefix) {
   if (GV.EVEX.state == InUsePrefix) {
     FailDecode(pMyDisasm);
   }
   else {
     if (GV.VEX.pp == 0x1) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vhaddpd ");
       #endif
       ArgsVEX(pMyDisasm);
     }
     else if (GV.VEX.pp == 0x3){
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vhaddps ");
       #endif
       ArgsVEX(pMyDisasm);
     }
     else {
       FailDecode(pMyDisasm);
     }
   }

 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "haddpd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
   else {
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "haddps ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
 }

}


/* ====================================================================
*      0x 0f 7d
* ==================================================================== */
void __bea_callspec__ hsubpd_VW(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.EVEX.state == InUsePrefix) {
     FailDecode(pMyDisasm);
   }
   else {
     if (GV.VEX.pp == 0x1) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vhsubpd ");
       #endif
       ArgsVEX(pMyDisasm);
     }
     else if (GV.VEX.pp == 0x3){
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vhsubps ");
       #endif
       ArgsVEX(pMyDisasm);
     }
     else {
       FailDecode(pMyDisasm);
     }
   }

 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hsubpd ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   else {
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hsubps ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
 }
}

/* ====================================================================
*      0x 0f 3a 30
* ==================================================================== */
void __bea_callspec__ kshiftrb(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.L == 0) {
      if (GV.VEX.pp == 1) {
        if (!Security(1, pMyDisasm)) return;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }

        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        if (GV.REX.W_ == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftrb ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftrw ");
          #endif
        }
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 33
* ==================================================================== */
void __bea_callspec__ kshiftld(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.L == 0) {
      if (GV.VEX.pp == 1) {
        if (!Security(1, pMyDisasm)) return;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }

        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        if (GV.REX.W_ == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftld ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftlq ");
          #endif
        }
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 32
* ==================================================================== */
void __bea_callspec__ kshiftlb(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.L == 0) {
      if (GV.VEX.pp == 1) {
        if (!Security(1, pMyDisasm)) return;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }

        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        if (GV.REX.W_ == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftlb ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftlw ");
          #endif
        }
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 31
* ==================================================================== */
void __bea_callspec__ kshiftrd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.L == 0) {
      if (GV.VEX.pp == 1) {
        if (!Security(1, pMyDisasm)) return;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }

        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        if (GV.REX.W_ == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftrd ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "kshiftrq ");
          #endif
        }
        GV.Register_ = OPMASK_REG;
        GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 67
* ==================================================================== */
void __bea_callspec__ vfpclassss(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfpclassss ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfpclasssd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 57
* ==================================================================== */
void __bea_callspec__ vreducess(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vreducess ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vreducesd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 55
* ==================================================================== */
void __bea_callspec__ vfixupmmss(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfixupmmss ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfixupmmsd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 51
* ==================================================================== */
void __bea_callspec__ vrangess(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrangess ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrangesd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 3a 27
* ==================================================================== */
void __bea_callspec__ vgetmantss(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetmantss ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetmantsd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 26
* ==================================================================== */
void __bea_callspec__ vgetmantps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetmantps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetmantpd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 25
* ==================================================================== */
void __bea_callspec__ vpternlogd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpternlogd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpternlogq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 43
* ==================================================================== */
void __bea_callspec__ vshufi32x4(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vshufi32x4 ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vshufi64x2 ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 23
* ==================================================================== */
void __bea_callspec__ vshuff32x4(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vshuff32x4 ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vshuff64x2 ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 21
* ==================================================================== */
void __bea_callspec__ insertps_(PDISASM pMyDisasm)
{

    if (GV.VEX.state == InUsePrefix) {
      if (GV.VEX.pp == 1) {
        if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
          FailDecode(pMyDisasm);
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinsertps ");
          #endif
          GV.MemDecoration = Arg3dword;

          if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
          if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;

          if (GV.VEX.L == 0) {
            (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
            GV.Register_ = SSE_REG;
          }
          else if (GV.VEX.L == 0x1) {
            (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
            GV.Register_ = AVX_REG;
          }
          else if (GV.EVEX.LL == 0x2) {
            (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
            GV.Register_ = AVX512_REG;
          }

          Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
          fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
          MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
          GV.EIP_ += GV.DECALAGE_EIP+2;

          getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
        }
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insertps ");
      #endif
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg2dword;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_+= GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}



/* ====================================================================
*      0x 0f f0
* ==================================================================== */
void __bea_callspec__ lddqu_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 3) {
      if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_ == 0x3) { FailDecode(pMyDisasm); return; }

      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+SPECIALIZED_128bits;
      #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vlddqu ");
      #endif
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
      (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SPECIALIZED_128bits;
      #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lddqu ");
      #endif
      GV.MemDecoration = Arg2_m128_xmm;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f f7
* ==================================================================== */
void __bea_callspec__ maskmovq_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }

    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+CACHEABILITY_CONTROL;
      #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaskmovdqu ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
      #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maskmovdqu ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
     else {
      GV.MemDecoration = Arg2qword;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
      #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maskmovq ");
      #endif
      GV.Register_ = MMX_REG;
      GxEx(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 28
* ==================================================================== */
void __bea_callspec__ movaps_VW(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     if (
         (GV.EVEX.state == InUsePrefix) &&
         (GV.EVEX.W == 1)
       ) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovaps ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
     ArgsVEX_GxEx(pMyDisasm);

   }
   else if (GV.VEX.pp == 1) {
     if (
         (GV.EVEX.state == InUsePrefix) &&
         (GV.EVEX.W == 0)
       ) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovapd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
     ArgsVEX_GxEx(pMyDisasm);

   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movapd ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   else {
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movaps ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }

 }
}

/* ====================================================================
*      0x 0f 29
* ==================================================================== */
void __bea_callspec__ movaps_WV(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     if (
         (GV.EVEX.state == InUsePrefix) &&
         (GV.EVEX.W == 1)
       ) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovaps ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
     ArgsVEX_ExGx(pMyDisasm);
   }
   else if (GV.VEX.pp == 1) {
     if (
         (GV.EVEX.state == InUsePrefix) &&
         (GV.EVEX.W == 0)
       ) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovapd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
     ArgsVEX_ExGx(pMyDisasm);
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     GV.MemDecoration = Arg1_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movapd ");
     #endif
     GV.Register_ = SSE_REG;
     ExGx(pMyDisasm);

   }
   else {
     GV.MemDecoration = Arg1_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movaps ");
     #endif
     GV.Register_ = SSE_REG;
     ExGx(pMyDisasm);

   }
 }
}


/* ====================================================================
*      0x 0f 16
* ==================================================================== */
void __bea_callspec__ movhps_VM(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     if (!Security(1, pMyDisasm)) return;
     GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_ == 0x3) {
       FailDecode(pMyDisasm);
     }
     else {
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_FIXED__64;
       ArgsVEX(pMyDisasm);
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovhpd ");
       #endif
       GV.MemDecoration = Arg3qword;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovshdup ");
     #endif
     ArgsVEX_GxEx(pMyDisasm);
   }
   else if (GV.VEX.pp == 0x0) {
     ArgsVEX(pMyDisasm);
     if (GV.MOD_ == 0x3) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovlhps ");
       #endif
     }
     else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovhps ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE2;
       GV.MemDecoration = Arg3qword;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========= 0xf3 */
   if (GV.PrefRepe == 1) {
     (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movshdup ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     GV.MemDecoration = Arg2qword;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhpd ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   else {
     GV.MemDecoration = Arg2qword;
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_== 0x3) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlhps ");
       #endif
     }
     else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhps ");
       #endif
     }
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
 }
}


/* ====================================================================
*      0x 0f 17
* ==================================================================== */
void __bea_callspec__ movhps_MV(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_== 0x3) {
         FailDecode(pMyDisasm);
     }
     else {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovhpd ");
       #endif
       GV.MemDecoration = Arg1qword;
     }
   }
   else {
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_== 0x3) {
         FailDecode(pMyDisasm);
     }
     else {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovhps ");
       #endif
       GV.MemDecoration = Arg1qword;
     }
   }
 } else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg1qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhpd ");
       #endif
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);

   }
   else {
       GV.MemDecoration = Arg1qword;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhps ");
       #endif
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);

   }
 }
}


/* ====================================================================
*      0x 0f 12
* ==================================================================== */
void __bea_callspec__ movlps_VM(PDISASM pMyDisasm)
{

    if (GV.VEX.state == InUsePrefix) {
      if (GV.VEX.pp == 0x1) {
       if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
       if (GV.MOD_ == 0x3) {
         FailDecode(pMyDisasm);
       }
       else {
         if (
              (GV.EVEX.state == InUsePrefix) &&
              (GV.EVEX.W == 0)
          ) {
          FailDecode(pMyDisasm);
         }
         else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovlpd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           ArgsVEX(pMyDisasm);
           GV.MemDecoration = Arg3qword;
         }
       }
     }
     else if (GV.VEX.pp == 0x2) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovsldup ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
       ArgsVEX_GxEx(pMyDisasm);
     }
     else if (GV.VEX.pp == 0x3) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovddup ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = MOVDDUP;
       ArgsVEX_GxEx(pMyDisasm);
       if (GV.VEX.L == 0) GV.MemDecoration = Arg2qword;
     }
     else {
       if (
            (GV.EVEX.state == InUsePrefix) &&
            (GV.EVEX.W == 1)
        ) {
        FailDecode(pMyDisasm);
       }
       else {
         ArgsVEX(pMyDisasm);
         if (GV.MOD_ == 0x3) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovhlps ");
           #endif
         }
         else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovlps ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE2;
           GV.MemDecoration = Arg3qword;
         }
       }
     }

   } else {
     /* ========= 0xf2 */
     if (GV.PrefRepne == 1) {
         (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
         GV.MemDecoration = Arg2qword;
         (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movddup ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
     /* ========= 0xf3 */
     else if (GV.PrefRepe == 1) {
         (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsldup ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
     /* ========== 0x66 */
     else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
         GV.OperandSize = GV.OriginalOperandSize;
         (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
         GV.MemDecoration = Arg2qword;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlpd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
     else {
         GV.MemDecoration = Arg2qword;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

         if (GV.MOD_== 0x3) {
             #ifndef BEA_LIGHT_DISASSEMBLY
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhlps ");
             #endif
         }
         else {
             #ifndef BEA_LIGHT_DISASSEMBLY
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlps ");
             #endif
         }
     }
   }
}


/* ====================================================================
*      0x 0f 13
* ==================================================================== */
void __bea_callspec__ movlps_MV(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_== 0x3) {
         FailDecode(pMyDisasm);
     }
     else {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovlpd ");
       #endif
       GV.MemDecoration = Arg1qword;
     }
   }
   else {
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_== 0x3) {
         FailDecode(pMyDisasm);
     }
     else {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovlps ");
       #endif
       GV.MemDecoration = Arg1qword;
     }
   }
 } else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg1qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlpd ");
       #endif
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);

   }
   else {
       GV.MemDecoration = Arg1qword;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlps ");
       #endif
       GV.Register_ = SSE_REG;
       ExGx(pMyDisasm);

   }
 }
}


/* ====================================================================
*      0x 0f 50
* ==================================================================== */
void __bea_callspec__ movmskps_(PDISASM pMyDisasm)
{
   if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
   if (GV.MOD_!= 0x3) {
       FailDecode(pMyDisasm);
   }
   else {
     if (GV.Architecture == 64) {
       GV.OperandSize = 64;
       GV.OriginalOperandSize = 64;
     }
     if (GV.EVEX.state == InUsePrefix) {
       FailDecode(pMyDisasm);
     }
     else if (GV.VEX.state == InUsePrefix) {
       if (GV.VEX.vvvv != 15) {
         GV.ERROR_OPCODE = UD_;
       }
       if (GV.VEX.pp == 1) {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+DATA_TRANSFER;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovmskpd ");
         #endif
         GV.Register_ = (GV.VEX.L == 0) ? SSE_REG : AVX_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_ += GV.DECALAGE_EIP+2;
       }
       else if (GV.VEX.pp == 0) {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+DATA_TRANSFER;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovmskps ");
         #endif
         GV.Register_ = (GV.VEX.L == 0) ? SSE_REG : AVX_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_ += GV.DECALAGE_EIP+2;
       }
       else {
         FailDecode(pMyDisasm);
       }
     }
     else {
       /* ========== 0x66 */
       if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
         GV.OperandSize = GV.OriginalOperandSize;
         (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movmskpd ");
         #endif
         GV.Register_ = SSE_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_ += GV.DECALAGE_EIP+2;
       }
       else {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movmskps ");
         #endif
         GV.Register_ = SSE_REG;
         MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
         GV.Register_ = 0;
         Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
         GV.EIP_ += GV.DECALAGE_EIP+2;
       }
     }
   }
}


/* ====================================================================
*      0x 0f 38 2a
* ==================================================================== */
void __bea_callspec__ movntdqa_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovntdqa ");
      #endif
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else if ((GV.VEX.pp == 2) && (GV.EVEX.state == InUsePrefix)) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastmb2q ");
      #endif
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = OPMASK_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }

    else {
      FailDecode(pMyDisasm);
    }
  }
  /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+STREAMING_LOAD;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntdqa ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f c3
* ==================================================================== */
void __bea_callspec__ movnti_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   FailDecode(pMyDisasm);
   return;
 }
 (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
 #ifndef BEA_LIGHT_DISASSEMBLY
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movnti ");
 #endif
 EvGv(pMyDisasm);

}


/* ====================================================================
*      0x 0f 2b
* ==================================================================== */
void __bea_callspec__ movntps_(PDISASM pMyDisasm)
{

 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 1)) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovntps ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
     ArgsVEX_ExGx(pMyDisasm);
   }
   else if (GV.VEX.pp == 1) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 0)) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovntpd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
     ArgsVEX_ExGx(pMyDisasm);
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
   if (GV.MOD_== 0x3) {
       FailDecode(pMyDisasm);
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg1_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntpd ");
       #endif
       GV.Register_ = SSE_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;

   }
   else {
       GV.MemDecoration = Arg1_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntps ");
       #endif
       GV.Register_ = SSE_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = 0;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
   }
 }
}


/* ====================================================================
*      0x 0f e7
* ==================================================================== */
void __bea_callspec__ movntq_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
        FailDecode(pMyDisasm);
        return;
      }
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      if (GV.EVEX.state == InUsePrefix) {
        GV.EVEX.tupletype = FULL_MEM;
      }
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovntdq ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX_ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
      FailDecode(pMyDisasm);
    }
     /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg1_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntdq ");
      #endif
      GV.Register_ = SSE_REG;
      ExGx(pMyDisasm);

    }
    else {
      GV.MemDecoration = Arg1qword;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntq ");
      #endif
      GV.Register_ = MMX_REG;
      ExGx(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 10
* ==================================================================== */
void __bea_callspec__ movups_VW(PDISASM pMyDisasm)
{
   if (GV.VEX.state == InUsePrefix) {
     if (GV.VEX.pp == 0x3) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       if (GV.VEX.vvvv == 0xF) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovsd ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
         GV.MemDecoration = Arg2qword;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovsd ");
         #endif
         ArgsVEX(pMyDisasm);
       }
     }
     else if (GV.VEX.pp == 0x2) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       if (GV.VEX.vvvv == 0xF) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovss ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
         GV.MemDecoration = Arg2dword;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovss ");
         #endif
         ArgsVEX(pMyDisasm);
       }
     }
     else if (GV.VEX.pp == 0x1) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovupd ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
       ArgsVEX_GxEx(pMyDisasm);
     }
     else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovups ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
       ArgsVEX_GxEx(pMyDisasm);
     }
   } else {
     /* ========= 0xf2 */
     if (GV.PrefRepne == 1) {
         (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
         GV.MemDecoration = Arg2qword;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);
     }
     /* ========= 0xf3 */
     else if (GV.PrefRepe == 1) {
         (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
         GV.MemDecoration = Arg2dword;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movss ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
     /* ========== 0x66 */
     else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
         GV.OperandSize = GV.OriginalOperandSize;
         (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movupd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
     else {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movups ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
   }
}

/* ====================================================================
*      0x 0f 11
* ==================================================================== */
void __bea_callspec__ movups_WV(PDISASM pMyDisasm)
{
   if (GV.VEX.state == InUsePrefix) {
     if (GV.VEX.pp == 0x3) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       if (GV.VEX.vvvv == 0xF) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovsd ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
         GV.MemDecoration = Arg1qword;
         GV.Register_ = SSE_REG;
         ExGx(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovsd ");
         #endif
         ArgsVEX_EyGy(pMyDisasm);
       }
     }
     else if (GV.VEX.pp == 0x2) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       if (GV.VEX.vvvv == 0xF) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovss ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
         GV.MemDecoration = Arg1dword;
         GV.Register_ = SSE_REG;
         ExGx(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovss ");
         #endif
         ArgsVEX_EyGy(pMyDisasm);
       }
     }
     else if (GV.VEX.pp == 0x1) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovupd ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
       ArgsVEX_ExGx(pMyDisasm);
     }
     else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovups ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
       ArgsVEX_ExGx(pMyDisasm);
     }
   } else {
     /* ========= 0xf2 */
     if (GV.PrefRepne == 1) {
         (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
         GV.MemDecoration = Arg1qword;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
         #endif
         GV.Register_ = SSE_REG;
         ExGx(pMyDisasm);

     }
     /* ========= 0xf3 */
     else if (GV.PrefRepe == 1) {
         (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
         GV.MemDecoration = Arg1dword;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movss ");
         #endif
         GV.Register_ = SSE_REG;
         ExGx(pMyDisasm);

     }
     /* ========== 0x66 */
     else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
         GV.OperandSize = GV.OriginalOperandSize;
         (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
         GV.MemDecoration = Arg1_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movupd ");
         #endif
         GV.Register_ = SSE_REG;
         ExGx(pMyDisasm);

     }
     else {
         GV.MemDecoration = Arg1_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movups ");
         #endif
         GV.Register_ = SSE_REG;
         ExGx(pMyDisasm);

     }
   }
}

/* ====================================================================
*      0x 0f 3a 42
* ==================================================================== */
void __bea_callspec__ mpsadbw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state  == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vdbpsadbw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmpsadbw ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mpsadbw ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 56
* ==================================================================== */
void __bea_callspec__ orps_VW(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {

     if (GV.VEX.state == InUsePrefix) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vorpd ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
       if (GV.VEX.opcode == 0xc4) {
         /* using VEX3Bytes */
         if (GV.REX.W_ == 0x1) {
             GV.OperandSize = 64;
         }
       }
       ArgsVEX(pMyDisasm);
     }
     else {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128d_xmm;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "orpd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);
     }
   }
   else {
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vorps ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         if (GV.VEX.opcode == 0xc4) {
           /* using VEX3Bytes */
           if (GV.REX.W_ == 0x1) {
               GV.OperandSize = 64;
           }
         }
         ArgsVEX(pMyDisasm);
       }
       else {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "orps ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
}
/* ====================================================================
*      0x 0f 3a 0f
* ==================================================================== */
void __bea_callspec__ palignr_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpalignr ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     GV.MemDecoration = Arg2_m128_xmm;
     GV.Register_ = SSE_REG;
    }
    else {
     GV.MemDecoration = Arg2qword;
     GV.Register_ = MMX_REG;
    }
    #ifndef BEA_LIGHT_DISASSEMBLY
     (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "palignr ");
    #endif

    GxEx(pMyDisasm);
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 19
* ==================================================================== */
void __bea_callspec__ vextractf128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextractf32x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextractf64x2 ");
        #endif
        GV.EVEX.tupletype = TUPLE2;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m128_xmm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextractf128 ");
        #endif
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
        GV.MemDecoration = Arg3_m128_xmm;
        if (GV.VEX.L == 0) {
          GV.Register_ = SSE_REG;
        }
        else {
          GV.Register_ = AVX_REG;
        }
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
        GV.Register_ = SSE_REG;
        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 3a 39
* ==================================================================== */
void __bea_callspec__ vextracti128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextracti32x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextracti64x2 ");
        #endif
        GV.EVEX.tupletype = TUPLE2;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m128_xmm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextracti128 ");
        #endif
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
        GV.MemDecoration = Arg3_m128_xmm;
        if (GV.VEX.L == 0) {
          GV.Register_ = SSE_REG;
        }
        else {
          GV.Register_ = AVX_REG;
        }
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
        GV.Register_ = SSE_REG;
        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 1d
* ==================================================================== */
void __bea_callspec__ vcvtps2ph(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtps2ph ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
        (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
        if (GV.VEX.L == 0) {
          GV.MemDecoration = Arg1qword;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.MemDecoration = Arg1_m128_xmm;
          GV.Register_ = SSE_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.MemDecoration = Arg1_m256_ymm;
          GV.Register_ = AVX_REG;
        }
        MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
        if (GV.VEX.L == 0) {
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.Register_ = AVX512_REG;
        }
        Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);

      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }

}


/* ====================================================================
*      0x 0f 3a 1b
* ==================================================================== */
void __bea_callspec__ vextractf32x8(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextractf32x8 ");
        #endif
        GV.EVEX.tupletype = TUPLE8;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextractf64x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m256_ymm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = AVX_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 3a 3b
* ==================================================================== */
void __bea_callspec__ vextracti32x8(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextracti32x8 ");
        #endif
        GV.EVEX.tupletype = TUPLE8;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vextracti64x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m256_ymm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = AVX_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 3a 1a
* ==================================================================== */
void __bea_callspec__ vinsertf32x8(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinsertf32x8 ");
        #endif
        GV.EVEX.tupletype = TUPLE8;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinsertf64x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m256_ymm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = AVX_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 3a 3a
* ==================================================================== */
void __bea_callspec__ vinserti32x8(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinserti32x8 ");
        #endif
        GV.EVEX.tupletype = TUPLE8;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinserti64x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m256_ymm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = AVX_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 18
* ==================================================================== */
void __bea_callspec__ vinsertf128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinsertf32x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinsertf64x2 ");
        #endif
        GV.EVEX.tupletype = TUPLE2;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m128_xmm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinsertf128 ");
        #endif
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
        GV.MemDecoration = Arg3_m128_xmm;
        if (GV.VEX.L == 0) {
          GV.Register_ = SSE_REG;
        }
        else {
          GV.Register_ = AVX_REG;
        }
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
        GV.Register_ = SSE_REG;
        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 3a 38
* ==================================================================== */
void __bea_callspec__ vinserti128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinserti32x4 ");
        #endif
        GV.EVEX.tupletype = TUPLE4;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinserti64x2 ");
        #endif
        GV.EVEX.tupletype = TUPLE2;
      }
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.MemDecoration = Arg3_m128_xmm;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 0) {
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vinserti128 ");
        #endif
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
        GV.MemDecoration = Arg3_m128_xmm;
        if (GV.VEX.L == 0) {
          GV.Register_ = SSE_REG;
        }
        else {
          GV.Register_ = AVX_REG;
        }
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
        GV.Register_ = SSE_REG;
        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }

}
/* ====================================================================
*      0x 0f 38 13
* ==================================================================== */
void __bea_callspec__ vcvtph2ps_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {

    if (GV.VEX.pp == 1) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (
          ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0)) ||
          ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0))
        ) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.EVEX.tupletype = HALF_MEM;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcvtph2ps ");
        #endif
        ArgsVEX_GE(pMyDisasm, Arg2qword, Arg2_m128_xmm, Arg2_m256_ymm, SSE_REG, SSE_REG, AVX_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else if (GV.VEX.pp == 2) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
      {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovusdw ");
        #endif
        GV.EVEX.tupletype = HALF_MEM;
        ArgsVEX_ExG(pMyDisasm, Arg1qword, Arg1_m128_xmm, Arg1_m256_ymm, SSE_REG, SSE_REG, AVX_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 12
* ==================================================================== */
void __bea_callspec__ vpsllvw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsllvw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovusqb ");
        #endif
        GV.EVEX.tupletype = EIGHTH_MEM;
        ArgsVEX_ExG(pMyDisasm, Arg1word, Arg1dword, Arg1qword, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 11
* ==================================================================== */
void __bea_callspec__ vpsravw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsravw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 0) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovusdb ");
        #endif
        GV.EVEX.tupletype = QUARTER_MEM;
        ArgsVEX_ExG(pMyDisasm, Arg1dword, Arg1qword, Arg1_m128_xmm, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 10 / 0x 0f 3a 4c
* ==================================================================== */
void __bea_callspec__ pblendvb_(PDISASM pMyDisasm)
{
  UInt8 Imm8;
  /* ========= 0xf3 */
  if ((GV.PrefRepe == 1) && (GV.EVEX.state == InUsePrefix)) {
    (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
    if (GV.EVEX.W == 0) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovuswb ");
      #endif
      GV.EVEX.tupletype = HALF_MEM;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg1qword;
        ExGx(pMyDisasm);
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg1_m128_xmm;
        MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.Register_ = AVX_REG;
        Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg1_m128_xmm;
        MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.Register_ = AVX512_REG;
        Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
    } else {
      FailDecode(pMyDisasm);
    }
  }
  /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.EVEX.state == InUsePrefix) {
      if (GV.EVEX.W == 1) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsrlvw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
      } else {
        FailDecode(pMyDisasm);
      }
    }
   else if (GV.VEX.state == InUsePrefix) {
     (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendvb ");
     #endif
     if (GV.VEX.opcode == 0xc4) {
       /* using VEX3Bytes */
       if (GV.REX.W_ == 0x1) {
         GV.ERROR_OPCODE = UD_;
       }
     }
     if (GV.VEX.L == 0) {
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg3_m128_xmm;
       GyEy(pMyDisasm);


       GV.EIP_++;
       if (!Security(0, pMyDisasm)) return;
       Imm8 = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
       fillRegister((Imm8 >> 4) & 0xF, &(*pMyDisasm).Operand4, pMyDisasm);

     }
     else {
       GV.Register_ = AVX_REG;
       GV.MemDecoration = Arg3_m256_ymm;
       GyEy(pMyDisasm);

       GV.EIP_++;
       if (!Security(0, pMyDisasm)) return;
       Imm8 = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
       fillRegister((Imm8 >> 4) & 0xF, &(*pMyDisasm).Operand4, pMyDisasm);
     }
   }
   else {
     (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
     GV.MemDecoration = Arg2_m128_xmm;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendvb ");
     #endif
     (*pMyDisasm).Operand3.AccessMode = READ;
     (*pMyDisasm).Operand3.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand3.Registers.type = SSE_REG;
  (*pMyDisasm).Operand3.Registers.xmm = REG0;
     (*pMyDisasm).Operand3.OpSize = 128;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((char*) (*pMyDisasm).Operand3.OpMnemonic, RegistersSSE[0]);
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);
   }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 0e
* ==================================================================== */
void __bea_callspec__ pblendw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendw ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendw ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

       getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
       FailDecode(pMyDisasm);
   }

}

/* ====================================================================
*      0x 0f 3a 61
* ==================================================================== */
void __bea_callspec__ pcmpestri_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      verifyVEXvvvv(pMyDisasm);
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+COMPARISON_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcmpestri ");
      #endif
      (*pMyDisasm).Operand1.AccessMode = READ;
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }

   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestri ");
       #endif
       (*pMyDisasm).Operand1.AccessMode = READ;
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

       getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
       FailDecode(pMyDisasm);
   }

}


/* ====================================================================
*      0x 0f 3a 60
* ==================================================================== */
void __bea_callspec__ pcmpestrm_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      verifyVEXvvvv(pMyDisasm);
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+COMPARISON_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcmpestrm ");
      #endif
      (*pMyDisasm).Operand1.AccessMode = READ;
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestrm ");
    #endif
    (*pMyDisasm).Operand1.AccessMode = READ;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
    FailDecode(pMyDisasm);
   }
}


/* ====================================================================
*      0x 0f 3a 63
* ==================================================================== */
void __bea_callspec__ pcmpistri_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      verifyVEXvvvv(pMyDisasm);
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+COMPARISON_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcmpistri ");
      #endif
      (*pMyDisasm).Operand1.AccessMode = READ;
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }

   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpistri ");
       #endif
       (*pMyDisasm).Operand1.AccessMode = READ;
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

       getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
       FailDecode(pMyDisasm);
   }

}

/* ====================================================================
*      0x 0f 3a f0
* ==================================================================== */
void __bea_callspec__ rorx_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 3) {
      (*pMyDisasm).Instruction.Category = BMI2_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rorx ");
      #endif
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      GV.OperandSize = (GV.REX.W_ == 1) ? 64 : 32;
      GV.MemDecoration = (GV.REX.W_ == 1) ? Arg2qword : Arg2dword;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 73
* ==================================================================== */
void __bea_callspec__ vpshrdd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshrdq ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshrdd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 71
* ==================================================================== */
void __bea_callspec__ vpshldd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshldq ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshldd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 72
* ==================================================================== */
void __bea_callspec__ vpshrdw(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshrdw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 70
* ==================================================================== */
void __bea_callspec__ vpshldw(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshldw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 62
* ==================================================================== */
void __bea_callspec__ pcmpistrm_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      verifyVEXvvvv(pMyDisasm);
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+COMPARISON_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcmpistrm ");
      #endif
      (*pMyDisasm).Operand1.AccessMode = READ;
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpistrm ");
       #endif
       (*pMyDisasm).Operand1.AccessMode = READ;
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

       getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
       FailDecode(pMyDisasm);
   }

}

/* ====================================================================
*      0x 0f 3a 14
* ==================================================================== */
void __bea_callspec__ pextrb_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      verifyVEXvvvv(pMyDisasm);
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      if (GV.REX.W_ == 1) {
        FailDecode(pMyDisasm);
      }
      else {
        if (GV.EVEX.state == InUsePrefix) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION+INSERTION_EXTRACTION;
          GV.EVEX.tupletype = TUPLE1_SCALAR;
        }
        else {
          (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+INSERTION_EXTRACTION;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpextrb ");
        #endif
        if (!Security(1, pMyDisasm)) return;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        GV.MemDecoration = (GV.MOD_== 0x3) ? Arg1dword : Arg1byte;
        MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.Register_ = SSE_REG;
        Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrb ");
      #endif
      if (!Security(1, pMyDisasm)) return;
      GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      GV.MemDecoration = (GV.MOD_== 0x3) ? Arg1dword : Arg1byte;
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }

}


/* ====================================================================
*      0x 0f 3a 16
* ==================================================================== */
void __bea_callspec__ pextrd_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      verifyVEXvvvv(pMyDisasm);
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      if
        (((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 1)) ||
        ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)))
       {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpextrq ");
         #endif
         GV.MemDecoration = Arg1qword;
         GV.OperandSize = 64;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpextrd ");
        #endif
        GV.MemDecoration = Arg1dword;
        GV.OperandSize = 32;
      }
      if (GV.EVEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION+INSERTION_EXTRACTION;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+INSERTION_EXTRACTION;
      }
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
      if (GV.REX.W_ == 0x1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrq ");
        #endif
        GV.MemDecoration = Arg1qword;
        GV.OperandSize = 64;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrd ");
        #endif
        GV.MemDecoration = Arg1dword;
      }
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f c5
* ==================================================================== */
void __bea_callspec__ pextrw_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 1) {
     if (
       (GV.EVEX.state != InUsePrefix) &&
       (GV.REX.W_ == 1)
     ) {
       FailDecode(pMyDisasm);
       return;
     }
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_!= 0x3) {
       FailDecode(pMyDisasm);
       return;
     }

     if (
       ((GV.EVEX.state != InUsePrefix) && ((GV.VEX.L == 1)||(GV.VEX.vvvv != 15))) ||
       ((GV.EVEX.state == InUsePrefix) && ((GV.EVEX.LL > 0)||(GV.EVEX.vvvv != 15)))
     ) {
       GV.ERROR_OPCODE = UD_;
     }
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpextrw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR__16;
     GV.OperandSize = 16;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
     GV.Register_ = SSE_REG;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

     GV.EIP_ += GV.DECALAGE_EIP+2;
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);

   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_!= 0x3) {
       FailDecode(pMyDisasm);
       return;
     }
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
     #endif
     GV.MemDecoration = Arg2_m128_xmm;
     GV.Register_ = SSE_REG;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
     GV.Register_ = 0;
     GV.OperandSize = 16;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
     GV.EIP_ += GV.DECALAGE_EIP+2;
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
     if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
     if (GV.MOD_!= 0x3) {
       FailDecode(pMyDisasm);
       return;
     }
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
     #endif
     GV.MemDecoration = Arg2dqword;
     GV.Register_ = MMX_REG;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
     GV.Register_ = 0;
     GV.OperandSize = 16;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
     GV.EIP_ += GV.DECALAGE_EIP+2;
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
 }
}

/* ====================================================================
*      0x 0f 3a 15
* ==================================================================== */
void __bea_callspec__ pextrw2_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      verifyVEXvvvv(pMyDisasm);
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;
      if (GV.REX.W_ == 1) {
        FailDecode(pMyDisasm);
      }
      else {
        if (GV.EVEX.state == InUsePrefix) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION+INSERTION_EXTRACTION;
          GV.EVEX.tupletype = TUPLE1_SCALAR;
        }
        else {
          (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+INSERTION_EXTRACTION;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpextrw ");
        #endif
        if (!Security(1, pMyDisasm)) return;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        GV.MemDecoration = (GV.MOD_== 0x3) ? Arg1dword : Arg1word;
        MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.Register_ = SSE_REG;
        Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
      #endif
      if (!Security(1, pMyDisasm)) return;
      GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_== 0x3) {
         GV.MemDecoration = Arg1dword;
      }
      else {
         GV.MemDecoration = Arg1word;
      }
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 38 02
* ==================================================================== */
void __bea_callspec__ phaddd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vphaddd ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddd ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddd ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 03
* ==================================================================== */
void __bea_callspec__ phaddsw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vphaddsw ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddsw ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddsw ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 01
* ==================================================================== */
void __bea_callspec__ phaddw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vphaddw ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;

    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddw ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddw ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 44
* ==================================================================== */
void __bea_callspec__ vplzcntd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vplzcntd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vplzcntq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 43
* ==================================================================== */
void __bea_callspec__ vgetexpss_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetexpss ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetexpsd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      GV.Register_ = SSE_REG;
      GyEy(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 54
* ==================================================================== */
void __bea_callspec__ vpopcntb_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpopcntb ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpopcntw ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 55
* ==================================================================== */
void __bea_callspec__ vpopcntd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpopcntd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpopcntq ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 50
* ==================================================================== */
void __bea_callspec__ vpdpbusd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpdpbusd ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 51
* ==================================================================== */
void __bea_callspec__ vpdpbusds_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpdpbusds ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 52
* ==================================================================== */
void __bea_callspec__ vpdpwssd_(PDISASM pMyDisasm)
{
  size_t i;
  int index;
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpdpwssd ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else if (GV.VEX.pp == 3) {
      if (GV.EVEX.W == 0) {
        if (GV.VEX.L == 2) {
          if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
          if ((GV.EVEX.b == 1) || (GV.MOD_ == 3)) GV.ERROR_OPCODE = UD_;
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vp4dpwssd ");
          #endif
          GV.EVEX.tupletype = TUPLE1_SCALAR;
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          GV.Register_ = AVX512_REG;
          GV.MemDecoration = Arg3_m128_xmm;
          Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

          index = (~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V;
          index = (index / 4) * 4;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, RegistersAVX512[index]);
             i = strlen((char*) &(*pMyDisasm).Operand2.OpMnemonic);
             (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, "...");
             i+=3;
             (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, RegistersAVX512[index+3]);
          #endif

          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = AVX512_REG;
          (*pMyDisasm).Operand2.Registers.zmm = REGS[index] + REGS[index+1] + REGS[index+2] + REGS[index+3];
          (*pMyDisasm).Operand2.OpSize = 512;

          MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
          GV.EIP_ += GV.DECALAGE_EIP+2;
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 53
* ==================================================================== */
void __bea_callspec__ vpdpwssds_(PDISASM pMyDisasm)
{
  size_t i;
  int index;
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpdpwssds ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else if (GV.VEX.pp == 3) {
      if (GV.EVEX.W == 0) {
        if (GV.VEX.L == 2) {
          if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
          if ((GV.EVEX.b == 1) || (GV.MOD_ == 3)) GV.ERROR_OPCODE = UD_;
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vp4dpwssds ");
          #endif
          GV.EVEX.tupletype = TUPLE1_SCALAR;
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          GV.Register_ = AVX512_REG;
          GV.MemDecoration = Arg3_m128_xmm;
          Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

          index = (~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V;
          index = (index / 4) * 4;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, RegistersAVX512[index]);
             i = strlen((char*) &(*pMyDisasm).Operand2.OpMnemonic);
             (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, "...");
             i+=3;
             (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, RegistersAVX512[index+3]);
          #endif

          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = AVX512_REG;
          (*pMyDisasm).Operand2.Registers.zmm = REGS[index] + REGS[index+1] + REGS[index+2] + REGS[index+3];
          (*pMyDisasm).Operand2.OpSize = 512;

          MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
          GV.EIP_ += GV.DECALAGE_EIP+2;
        }
        else {
          FailDecode(pMyDisasm);
        }
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 42
* ==================================================================== */
void __bea_callspec__ vgetexpps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetexpps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgetexppd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 41
* ==================================================================== */
void __bea_callspec__ phminposuw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if ((GV.VEX.L != 0) || (GV.VEX.vvvv != 15)) GV.ERROR_OPCODE = UD_;
    (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+HORIZONTAL_SEARCH;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vphminposuw ");
    #endif
    GV.Register_ = SSE_REG;
    GV.MemDecoration = Arg2_m128_xmm;
    GxEx(pMyDisasm);
  }

   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+HORIZONTAL_SEARCH;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phminposuw ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 05
* ==================================================================== */
void __bea_callspec__ phsubw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vphsubw ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;

    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubw ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubw ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
   }
}


/* ====================================================================
*      0x 0f 38 06
* ==================================================================== */
void __bea_callspec__ phsubd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vphsubd ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubd ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubd ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 0e
* ==================================================================== */
void __bea_callspec__ vtestps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if ((GV.REX.W_ == 1) || (GV.VEX.vvvv != 15)) {
        GV.ERROR_OPCODE = UD_;
      }
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vtestps ");
      #endif
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg2_m128_xmm;
        GxEx(pMyDisasm);
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg2_m256_ymm;
        GxEx(pMyDisasm);
      }
      (*pMyDisasm).Operand1.AccessMode = READ;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 0f
* ==================================================================== */
void __bea_callspec__ vtestpd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if ((GV.REX.W_ == 1) || (GV.VEX.vvvv != 15)) {
        GV.ERROR_OPCODE = UD_;
      }
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vtestpd ");
      #endif
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg2_m128_xmm;
        GxEx(pMyDisasm);
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg2_m256_ymm;
        GxEx(pMyDisasm);
      }
      (*pMyDisasm).Operand1.AccessMode = READ;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}
/* ====================================================================
*      0x 0f 38 07
* ==================================================================== */
void __bea_callspec__ phsubsw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vphsubsw ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubsw ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubsw ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 20
* ==================================================================== */
void __bea_callspec__ pinsrb_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 1) {
        FailDecode(pMyDisasm);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpinsrb ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;

        if (GV.VEX.L == 0) {
          (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
          GV.Register_ = AVX512_REG;
        }
        GV.MemDecoration = Arg3byte;
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
        GV.Register_ = 0;
        GV.OperandSize = 32;
        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2byte;
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrb ");
      #endif
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 3a 22
* ==================================================================== */
void __bea_callspec__ pinsrd_(PDISASM pMyDisasm)
{

  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {

      if ((GV.EVEX.W == 1) || (GV.REX.W_ == 1)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpinsrq ");
        #endif
        GV.MemDecoration = Arg3qword;
        GV.OperandSize = 64;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpinsrd ");
        #endif
        GV.MemDecoration = Arg3dword;
        GV.OperandSize = 32;
      }

      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
      if (GV.VEX.L != 0) GV.ERROR_OPCODE = UD_;

      if (GV.VEX.L == 0) {
        (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.Register_ = AVX512_REG;
      }

      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = 0;
      GV.OperandSize = 32;
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;

      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {

   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
       if (GV.REX.W_ == 0x1) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrq ");
           #endif
           GV.MemDecoration = Arg2qword;
           GV.OperandSize = 64;
       }
       else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrd ");
           #endif
           GV.MemDecoration = Arg2dword;
       }
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = SSE_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
       getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
       FailDecode(pMyDisasm);
   }
 }

}


/* ====================================================================
*      0x 0f c4
* ==================================================================== */
void __bea_callspec__ pinsrw_(PDISASM pMyDisasm)
{

 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 1) {
     if ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 1))
     {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpinsrw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR__16;
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     if (
       ((GV.EVEX.state != InUsePrefix) && (GV.VEX.L != 0)) ||
       ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.LL != 0))
     )
     {
       GV.ERROR_OPCODE = UD_;
     }
     GV.Register_ = SSE_REG;
     GV.MemDecoration = Arg3word;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
     fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
     GV.Register_ = 0;
     GV.OperandSize = 32;
     MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
     GV.EIP_ += GV.DECALAGE_EIP+2;
     getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrw ");
     #endif
     GV.MemDecoration = Arg2word;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
     GV.Register_ = SSE_REG;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

     GV.EIP_ += GV.DECALAGE_EIP+2;
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrw ");
     #endif
     GV.MemDecoration = Arg2word;
     MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
     GV.Register_ = MMX_REG;
     Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

     GV.EIP_ += GV.DECALAGE_EIP+2;
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
 }
}

/* ====================================================================
*      0x 0f 38 04
* ==================================================================== */
void __bea_callspec__ pmaddubsw_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaddubsw ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddubsw ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
   }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddubsw ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 80
* ==================================================================== */
void __bea_callspec__ invept_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
  if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
  if (GV.MOD_ == 0x3){ FailDecode(pMyDisasm); return; }
  if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2dqword;
    if (GV.Architecture == 64) GV.OperandSize = 64;
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "invept ");
    #endif
    GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 81
* ==================================================================== */
void __bea_callspec__ invvpid_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
  if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
  if (GV.MOD_ == 0x3){ FailDecode(pMyDisasm); return; }
  if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2dqword;
    if (GV.Architecture == 64) GV.OperandSize = 64;
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "invvpid ");
    #endif
    GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 82
* ==================================================================== */
void __bea_callspec__ invpcid_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
  if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
  if (GV.MOD_ == 0x3){ FailDecode(pMyDisasm); return; }
  if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2dqword;
    if (GV.Architecture == 64) GV.OperandSize = 64;
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "invpcid ");
    #endif
    GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}
/* ====================================================================
*      0x 0f d7
* ==================================================================== */
void __bea_callspec__ pmovmskb_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.EVEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ != 0x3) { FailDecode(pMyDisasm); return; }
    if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovmskb ");
    #endif
    if (GV.VEX.L == 0) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg2_m128_xmm;
    }
    else if (GV.VEX.L == 0x1) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
      GV.Register_ = AVX_REG;
      GV.MemDecoration = Arg2_m256_ymm;
    }
    MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
    GV.Register_ = 0;
    if (GV.Architecture == 64) GV.OperandSize = 64;
    Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP+2;
  }
  else {
    if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_ != 0x3){ FailDecode(pMyDisasm); return; }

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovmskb ");
      #endif
      if (GV.Architecture == 64) GV.OperandSize = 64;
      GV.MemDecoration = Arg2_m128_xmm;
      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = 0;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovmskb ");
      #endif
      if (GV.Architecture == 64) {
        GV.OperandSize = 64;
      }
      GV.MemDecoration = Arg2qword;
      GV.Register_ = MMX_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.Register_ = 0;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
  }
}

/* ====================================================================
*      0x 0f 38 0b
* ==================================================================== */
void __bea_callspec__ pmulhrsw_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmulhrsw ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhrsw ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhrsw ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 04
* ==================================================================== */
void __bea_callspec__ vpermilps2(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
        FailDecode(pMyDisasm);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermilps ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
        verifyVEXvvvv(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 05
* ==================================================================== */
void __bea_callspec__ vpermilpd2(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
      if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
        FailDecode(pMyDisasm);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermilpd ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
        verifyVEXvvvv(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 3a 06
* ==================================================================== */
void __bea_callspec__ vperm2f128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L != 1) GV.ERROR_OPCODE = UD_;
      if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vperm2f128 ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 0c
* ==================================================================== */
void __bea_callspec__ vpermilps_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 1) {
        GV.ERROR_OPCODE = UD_;
      }
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermilps ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 0d
* ==================================================================== */
void __bea_callspec__ vpermilpd_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermilpd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* =======================================
*      0x 0f b8
* ======================================= */
void __bea_callspec__ popcnt_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   FailDecode(pMyDisasm);
   return;
 }
 (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+DATA_TRANSFER;
 #ifndef BEA_LIGHT_DISASSEMBLY
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popcnt ");
 #endif
 GvEv(pMyDisasm);
 FillFlags(pMyDisasm,114);
}

/* ====================================================================
*      0x 0f 38 00
* ==================================================================== */
void __bea_callspec__ pshufb_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += SHUFFLE_UNPACK;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshufb ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  } else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufb ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
   }
   else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufb ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
   }
}


/* ====================================================================
*      0x 0f 70
* ==================================================================== */
void __bea_callspec__ pshufw_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     FailDecode(pMyDisasm);
   }
   else if (GV.VEX.pp == 1) {
     if (
         (GV.EVEX.state == InUsePrefix) &&
         (GV.EVEX.W == 1)
       ) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshufd ");
     #endif
     ArgsVEX_GxEx(pMyDisasm);
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
     verifyVEXvvvv(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshufhw ");
     #endif
     ArgsVEX_GxEx(pMyDisasm);
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
     verifyVEXvvvv(pMyDisasm);
   }
   else {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshuflw ");
     #endif
     ArgsVEX_GxEx(pMyDisasm);
     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
     verifyVEXvvvv(pMyDisasm);
   }
 }
 else {
   (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
   /* ========= 0xf3 */
   if (GV.PrefRepe == 1) {
     (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;

     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufhw ");
     #endif
     GV.MemDecoration = Arg2_m128_xmm;
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   /* ========= 0xf2 */
   else if (GV.PrefRepne == 1) {
     (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;

     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshuflw ");
     #endif
     GV.MemDecoration = Arg2_m128_xmm;
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;

     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufd ");
     #endif
     GV.MemDecoration = Arg2_m128_xmm;
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
   else {

     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufw ");
     #endif
     GV.MemDecoration = Arg2qword;
     GV.Register_ = MMX_REG;
     GxEx(pMyDisasm);

     getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
   }
 }
}

/* ====================================================================
*      0x 0f 38 08
* ==================================================================== */
void __bea_callspec__ psignb_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsignb ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }

  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;

    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignb ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignb ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 0a
* ==================================================================== */
void __bea_callspec__ psignd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsignd ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;

    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignd ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignd ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 36
* ==================================================================== */
void __bea_callspec__ vpermd_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermq ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermd ");
        #endif
      }
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 09
* ==================================================================== */
void __bea_callspec__ psignw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  } else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsignw ");
      #endif
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }

  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;

    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignw ");
    #endif
    GV.MemDecoration = Arg2_m128_xmm;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignw ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 27
* ==================================================================== */
void __bea_callspec__ vptestmd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestmq ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestmd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestnmq ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestnmd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 26
* ==================================================================== */
void __bea_callspec__ vptestmb_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestmw ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestmb ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestnmw ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptestnmb ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      GV.EVEX.masking = MERGING;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 16
* ==================================================================== */
void __bea_callspec__ vpermps_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
      if (GV.VEX.pp == 1) {
        if (
            ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0)) ||
            ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0))
          ) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermps ");
          #endif
          if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
          if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
          ArgsVEX(pMyDisasm);
        }
        else if (GV.EVEX.W == 1) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermpd ");
          #endif
          if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
          if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
          ArgsVEX(pMyDisasm);
        }
        else {
          FailDecode(pMyDisasm);
        }

      }
      else {
        FailDecode(pMyDisasm);
      }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 17
* ==================================================================== */
void __bea_callspec__ ptest_(PDISASM pMyDisasm)
{

  if (GV.VEX.state == InUsePrefix) {
    if (GV.EVEX.state == InUsePrefix) { FailDecode(pMyDisasm); return; }
    if (GV.VEX.pp == 1) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+PACKED_TEST;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vptest ");
      #endif
      if (GV.VEX.L == 0) {
        GV.MemDecoration = Arg2_m128_xmm;
        GV.Register_ = SSE_REG;
      }
      else {
        GV.MemDecoration = Arg2_m256_ymm;
        GV.Register_ = AVX_REG;
      }

      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_TEST;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ptest ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 3a 09
* ==================================================================== */
void __bea_callspec__ roundpd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrndscalepd ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vroundpd ");
      #endif
      ArgsVEX_GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundpd ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 08
* ==================================================================== */
void __bea_callspec__ roundps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrndscaleps ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX_GxEx(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vroundps ");
      #endif
      ArgsVEX_GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundps ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 3a 0b
* ==================================================================== */
void __bea_callspec__ roundsd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrndscalesd ");
        #endif
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
        GV.MemDecoration = Arg3qword;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vroundsd ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      GV.MemDecoration = Arg3qword;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundsd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

       getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);

   }
   else {
       FailDecode(pMyDisasm);
   }
}


/* ====================================================================
*      0x 0f 3a 0a
* ==================================================================== */
void __bea_callspec__ roundss_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrndscaless ");
        #endif
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX(pMyDisasm);
        getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
        GV.MemDecoration = Arg3dword;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vroundss ");
      #endif
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
      GV.MemDecoration = Arg3dword;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2dword;
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundss ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f c6
* ==================================================================== */
void __bea_callspec__ shufps_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 0) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vshufps ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vshufpd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shufpd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHUFFLE_UNPACK;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shufps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    (*pMyDisasm).Operand1.AccessMode = READ;
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 2e
* ==================================================================== */
void __bea_callspec__ ucomiss_VW(PDISASM pMyDisasm)
{

 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 1)
     ) {
       FailDecode(pMyDisasm);
       return;
     }
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vucomiss ");
     #endif
     GV.MemDecoration = Arg2dword;
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15))
         || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }

   }
   else if (GV.VEX.pp == 1) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 0)
     ) {
       FailDecode(pMyDisasm);
       return;
     }
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vucomisd ");
     #endif
     GV.MemDecoration = Arg2qword;
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if (GV.OperandSize == 16) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ucomisd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
   else {
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ucomiss ");
       #endif
       GV.MemDecoration = Arg2dword;
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);
   }
 }
}


/* ====================================================================
*      0x 0f 15
* ==================================================================== */
void __bea_callspec__ unpckhps_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : SSE2_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vunpckhpd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
     ArgsVEX(pMyDisasm);
   }
   else {
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : SSE_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vunpckhps ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
     ArgsVEX(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if (GV.OperandSize == 16) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpckhpd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
   else {
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpckhps ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
 }
}

/* ====================================================================
*      0x 0f 14
* ==================================================================== */
void __bea_callspec__ unpcklps_(PDISASM pMyDisasm)
{
   if (GV.VEX.state == InUsePrefix) {
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : SSE_INSTRUCTION;
     if (GV.VEX.pp == 0x1) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vunpcklpd ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
       ArgsVEX(pMyDisasm);
     }
     else {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : SSE_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vunpcklps ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
       ArgsVEX(pMyDisasm);
     }
   }
   else {
     /* ========== 0x66 */
     if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
         GV.OperandSize = GV.OriginalOperandSize;
         (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpcklpd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
     else {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpcklps ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

     }
   }
}


/* ====================================================================
*      0x 0f 57
* ==================================================================== */
void __bea_callspec__ xorps_VW(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {

     if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vxorpd ");
       #endif
       if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;

       if (GV.VEX.opcode == 0xc4) {
         /* using VEX3Bytes */
         if (GV.REX.W_ == 0x1) {
             GV.OperandSize = 64;
         }
       }
       ArgsVEX(pMyDisasm);
     }
     else {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       GV.MemDecoration = Arg2_m128d_xmm;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xorpd ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

     }
   }
   else {
       if (GV.VEX.state == InUsePrefix) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vxorps ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         if (GV.VEX.opcode == 0xc4) {
           /* using VEX3Bytes */
           if (GV.REX.W_ == 0x1) {
               GV.OperandSize = 64;
           }
         }
         ArgsVEX(pMyDisasm);
       }
       else {
         GV.MemDecoration = Arg2_m128_xmm;
         (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xorps ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
}

/* ====================================================================
*      0x 0f 38 29
* ==================================================================== */

void __bea_callspec__ pcmpeqq_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovb2m ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovw2m ");
        #endif
      }
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcmpeqq ");
      #endif
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcmpeqq ");
      #endif
      ArgsVEX(pMyDisasm);
    } else {
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqq ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 38 3e
* ==================================================================== */

void __bea_callspec__ pmaxuw_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxuw ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxuw ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 45
* ==================================================================== */

void __bea_callspec__ psrlvd_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsrlvq ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsrlvd ");
           #endif
         }
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlvd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 38
* ==================================================================== */

void __bea_callspec__ pminsb_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovm2d ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovm2q ");
        #endif
      }
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = OPMASK_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminsb ");
      #endif
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminsb ");
      #endif
      ArgsVEX(pMyDisasm);
    } else {
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsb ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 4f
* ==================================================================== */

void __bea_callspec__ vrsqrt14ss_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt14ss ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt14sd ");
        #endif
      }
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg2_m128_xmm;
      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 4e
* ==================================================================== */

void __bea_callspec__ vrsqrt14ps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt14ps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt14pd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 4d
* ==================================================================== */

void __bea_callspec__ vrcp14ss_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp14ss ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp14sd ");
        #endif
      }
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg2_m128_xmm;
      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 4c
* ==================================================================== */

void __bea_callspec__ vrcp14ps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp14ps ");
        #endif

      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp14pd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 3a
* ==================================================================== */

void __bea_callspec__ pminuw_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminuw ");
      #endif
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else if ((GV.VEX.pp == 2) && (GV.EVEX.state == InUsePrefix)) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastmw2d ");
      #endif
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = OPMASK_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }

    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminuw ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 38 3f
* ==================================================================== */

void __bea_callspec__ pmaxud_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxud ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxuq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }

   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxud ");
         #endif
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxud ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 39
* ==================================================================== */

void __bea_callspec__ pminsd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovd2m ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovq2m ");
        #endif
      }
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminsd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminsq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    /* ========== 0x66 */
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminsd ");
      #endif
      ArgsVEX(pMyDisasm);
    } else {
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 38 46
* ==================================================================== */

void __bea_callspec__ psravd_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsravq ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsravd ");
           #endif
         }
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psravd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 37
* ==================================================================== */

void __bea_callspec__ pcmpgtq_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcmpgtq ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtq ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 3c
* ==================================================================== */

void __bea_callspec__ pmaxsb_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxsb ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsb ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}

/* ====================================================================
*      0x 0f 38 2f
* ==================================================================== */

void __bea_callspec__ vmaskmovpd2_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaskmovpd ");
    #endif
    ArgsVEX_EyGy(pMyDisasm);
    if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 2e
* ==================================================================== */

void __bea_callspec__ vmaskmovps2_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaskmovps ");
    #endif
    ArgsVEX_EyGy(pMyDisasm);
    if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 2d
* ==================================================================== */

void __bea_callspec__ vmaskmovpd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscalefss ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscalefsd ");
        #endif
      }
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg3_m128_xmm;
      GyEy(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaskmovpd ");
    #endif
    ArgsVEX(pMyDisasm);
    if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 2c
* ==================================================================== */

void __bea_callspec__ vmaskmovps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscalefps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscalefpd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaskmovps ");
    #endif
    ArgsVEX(pMyDisasm);
    if (GV.REX.W_ == 1) GV.ERROR_OPCODE = UD_;
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 2b
* ==================================================================== */

void __bea_callspec__ packusdw_(PDISASM pMyDisasm)
{
  /* ========== 0x66 */
  if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpackusdw ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    } else {
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packusdw ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
  else {
     FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 3d
* ==================================================================== */

void __bea_callspec__ pmaxsd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxsd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxsq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaxsd ");
         #endif
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 3b
* ==================================================================== */

void __bea_callspec__ pminud_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminud ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminuq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpminud ");
         #endif
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminud ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 28
* ==================================================================== */

void __bea_callspec__ pmuldq_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 2) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovm2b ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovm2w ");
        #endif
      }
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = OPMASK_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

      if (GV.MOD_ != 3) {
        GV.MemDecoration = Arg2multibytes;
        GV.ERROR_OPCODE = UD_;
      }
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmuldq ");
      #endif
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    /* ========== 0x66 */
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmuldq ");
      #endif
      ArgsVEX(pMyDisasm);
    } else {
      (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmuldq ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 38 40
* ==================================================================== */

void __bea_callspec__ pmulld_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmullq ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmulld ");
           #endif
         }
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulld ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 47
* ==================================================================== */

void __bea_callspec__ psllvd_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 1)) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsllvq ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpsllvd ");
           #endif
         }
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION;
         GV.MemDecoration = Arg2_m128_xmm;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllvd ");
         #endif
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 ac
* ==================================================================== */

void __bea_callspec__ vfnmadd213ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd213ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd213pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 ad
* ==================================================================== */

void __bea_callspec__ vfnmadd213ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd213ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd213sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 bb
* ==================================================================== */

void __bea_callspec__ vfmsub231ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub231ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub231sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 92
* ==================================================================== */

void __bea_callspec__ vgatherps_(PDISASM pMyDisasm)
{
 /* ========== 0x66 */
 if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   if (GV.VEX.state == InUsePrefix) {
     if (
         ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgatherdps ");
       #endif
       GV.EVEX.masking = MERGING;
       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2dword;
           GxExVEX(pMyDisasm);
         }
         else {
           GV.MemDecoration = Arg2dword;
           GxEx(pMyDisasm);
         }
       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;

         if (GV.EVEX.state != InUsePrefix) {
           GV.Register_ = SSE_REG;
           GV.MemDecoration = Arg2dword;
           GxExVEX(pMyDisasm);
         }
         else {
           GV.Register_ = SSE_REG;
           GV.MemDecoration = Arg2dword;
           GxEx(pMyDisasm);
         }
       }
       else if (GV.EVEX.LL == 0x2) {
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX_REG;
         GV.MemDecoration = Arg2dword;
         GxEx(pMyDisasm);
       }
     } else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgatherdpd ");
       #endif
       GV.EVEX.masking = MERGING;
       GV.MemDecoration = Arg2dword;
       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GxExVEX(pMyDisasm);
         }
         else {
           GxEx(pMyDisasm);
         }
       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;
         GV.Register_ = AVX_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2dword;
           GxExVEX(pMyDisasm);
         }
         else {
           GV.MemDecoration = Arg2dword;
           GxEx(pMyDisasm);
         }
       }
       else if (GV.EVEX.LL == 0x2) {
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX512_REG;
         GV.MemDecoration = Arg2dword;
         GxEx(pMyDisasm);

       }
     }
   } else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 ae
* ==================================================================== */

void __bea_callspec__ vfnmsub213ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub213ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub213pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 a7
* ==================================================================== */

void __bea_callspec__ vfmsubadd213ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsubadd213ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsubadd213pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 b6
* ==================================================================== */

void __bea_callspec__ vfmaddsub231ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (
            ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
            ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmaddsub231ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmaddsub231pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 97
* ==================================================================== */

void __bea_callspec__ vfmsubadd132ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (
            ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
            ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsubadd132ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsubadd132pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 9c
* ==================================================================== */

void __bea_callspec__ vfnmadd132ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (
            ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
            ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd132ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd132pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 9d
* ==================================================================== */

void __bea_callspec__ vfnmadd132ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (
           ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
           ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd132ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd132sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 98
* ==================================================================== */

void __bea_callspec__ vfmadd132ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd132ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd132pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 9f
* ==================================================================== */

void __bea_callspec__ vfnmsub132ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub132ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub132sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 9e
* ==================================================================== */

void __bea_callspec__ vfnmsub132ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub132ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub132pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}


/* ====================================================================
*      0x 0f 38 91
* ==================================================================== */

void __bea_callspec__ vgatherqd_(PDISASM pMyDisasm)
{
 /* ========== 0x66 */
 if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   if (GV.VEX.state == InUsePrefix) {
     if (
         ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpgatherqd ");
       #endif
       GV.EVEX.masking = MERGING;
       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2qword;
           GxExVEX(pMyDisasm);
         }
         else {
           GV.MemDecoration = Arg2qword;
           GxEx(pMyDisasm);
         }
       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;

         if (GV.EVEX.state != InUsePrefix) {
           GV.Register_ = AVX_REG;
           GV.MemDecoration = Arg2qword;
           GxExVEX(pMyDisasm);
         }
         else {
           GV.Register_ = AVX_REG;
           GV.MemDecoration = Arg2qword;
           GxEx(pMyDisasm);
         }
       }
       else if (GV.EVEX.LL == 0x2) {
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX512_REG;
         GV.MemDecoration = Arg2qword;
         GxEx(pMyDisasm);

       }

     } else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpgatherqq ");
       #endif
       GV.EVEX.masking = MERGING;
       GV.MemDecoration = Arg2qword;
       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GxExVEX(pMyDisasm);

         }
         else {
           GxEx(pMyDisasm);
         }

       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;
         GV.Register_ = AVX_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2qword;
           GxExVEX(pMyDisasm);

         }
         else {
           GV.MemDecoration = Arg2qword;
           GxEx(pMyDisasm);
         }

       }
       else if (GV.EVEX.LL == 0x2) {
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX512_REG;
         GV.MemDecoration = Arg2qword;
         GxEx(pMyDisasm);

       }
     }
   } else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 99
* ==================================================================== */

void __bea_callspec__ vfmadd132ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd132ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd132sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 bc
* ==================================================================== */

void __bea_callspec__ vfnmadd231ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd231ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd231pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 9a
* ==================================================================== */

void __bea_callspec__ vfmsub132ps_(PDISASM pMyDisasm)
{
  size_t i;
  int index;
  if ((GV.EVEX.state == InUsePrefix) && (GV.VEX.pp == 3)) {
    if (GV.EVEX.W == 0) {
      if (GV.VEX.L == 2) {
        if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if ((GV.EVEX.b == 1) || (GV.MOD_ == 3)) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "v4fmaddps ");
        #endif
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m128_xmm;
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

        index = (~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V;
        index = (index / 4) * 4;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, RegistersAVX512[index]);
           i = strlen((char*) &(*pMyDisasm).Operand2.OpMnemonic);
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, "...");
           i+=3;
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, RegistersAVX512[index+3]);
        #endif

        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand2.Registers.type = AVX512_REG;
        (*pMyDisasm).Operand2.Registers.zmm = REGS[index] + REGS[index+1] + REGS[index+2] + REGS[index+3];
        (*pMyDisasm).Operand2.OpSize = 512;

        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
     if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub132ps ");
       #endif
     } else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub132pd ");
       #endif

     }
     ArgsVEX(pMyDisasm);
    } else {
     FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 90
* ==================================================================== */

void __bea_callspec__ vgatherdd_(PDISASM pMyDisasm)
{

 /* ========== 0x66 */
 if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   if (GV.VEX.state == InUsePrefix) {
     if (
         ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpgatherdd ");
       #endif
       GV.EVEX.masking = MERGING;

       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2dword;
           GxExVEX(pMyDisasm);
         }
         else {
           GV.MemDecoration = Arg2dword;
           GxEx(pMyDisasm);
         }

       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;

         if (GV.EVEX.state != InUsePrefix) {
           GV.Register_ = AVX_REG;
           GV.MemDecoration = Arg2dword;
           GxExVEX(pMyDisasm);


         }
         else {
           GV.Register_ = AVX_REG;
           GV.MemDecoration = Arg2dword;
           GxEx(pMyDisasm);

         }
       }
       else if (GV.EVEX.LL == 0x2) {
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX512_REG;
         GV.MemDecoration = Arg2dword;
         GxEx(pMyDisasm);

       }

     } else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpgatherdq ");
       #endif
       GV.EVEX.masking = MERGING;
       GV.MemDecoration = Arg2dword;
       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GxExVEX(pMyDisasm);

         }
         else {
           GxEx(pMyDisasm);
         }

       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;
         GV.Register_ = AVX_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2dword;
           GxExVEX(pMyDisasm);

         }
         else {
           GV.MemDecoration = Arg2dword;
           GxEx(pMyDisasm);
         }

       }
       else if (GV.EVEX.LL == 0x2) {
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX512_REG;
         GV.MemDecoration = Arg2dword;
         GxEx(pMyDisasm);

       }
     }
   } else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 b7
* ==================================================================== */

void __bea_callspec__ vfmsubadd231ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsubadd231ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsubadd231pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 a6
* ==================================================================== */

void __bea_callspec__ vfmaddsub213ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmaddsub213ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmaddsub213pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 9b
* ==================================================================== */

void __bea_callspec__ vfmsub132ss_(PDISASM pMyDisasm)
{
  size_t i;
  int index;
  if ((GV.EVEX.state == InUsePrefix) && (GV.VEX.pp == 3)) {
    if (GV.EVEX.W == 0) {
      if (GV.VEX.L == 2) {
        if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if ((GV.EVEX.b == 1) || (GV.MOD_ == 3)) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "v4fmaddss ");
        #endif
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m128_xmm;
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

        index = (~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V;
        index = (index / 4) * 4;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, RegistersAVX512[index]);
           i = strlen((char*) &(*pMyDisasm).Operand2.OpMnemonic);
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, "...");
           i+=3;
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, RegistersAVX512[index+3]);
        #endif

        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand2.Registers.type = AVX512_REG;
        (*pMyDisasm).Operand2.Registers.zmm = REGS[index] + REGS[index+1] + REGS[index+2] + REGS[index+3];
        (*pMyDisasm).Operand2.OpSize = 512;

        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub132ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub132sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 aa
* ==================================================================== */

void __bea_callspec__ vfmsub213ps_(PDISASM pMyDisasm)
{
  size_t i;
  int index;
  if ((GV.EVEX.state == InUsePrefix) && (GV.VEX.pp == 3)) {
    if (GV.EVEX.W == 0) {
      if (GV.VEX.L == 2) {
        if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if ((GV.EVEX.b == 1) || (GV.MOD_ == 3)) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "v4fnmaddps ");
        #endif
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m128_xmm;
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

        index = (~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V;
        index = (index / 4) * 4;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, RegistersAVX512[index]);
           i = strlen((char*) &(*pMyDisasm).Operand2.OpMnemonic);
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, "...");
           i+=3;
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, RegistersAVX512[index+3]);
        #endif

        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand2.Registers.type = AVX512_REG;
        (*pMyDisasm).Operand2.Registers.zmm = REGS[index] + REGS[index+1] + REGS[index+2] + REGS[index+3];
        (*pMyDisasm).Operand2.OpSize = 512;

        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub213ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub213pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 bd
* ==================================================================== */

void __bea_callspec__ vfnmadd231ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd231ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmadd231sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 b9
* ==================================================================== */

void __bea_callspec__ vfmadd231ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd231ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd231sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 ab
* ==================================================================== */

void __bea_callspec__ vfmsub213ss_(PDISASM pMyDisasm)
{
  size_t i;
  int index;
  if ((GV.EVEX.state == InUsePrefix) && (GV.VEX.pp == 3)) {
    if (GV.EVEX.W == 0) {
      if (GV.VEX.L == 2) {
        if (!Security(1, pMyDisasm)) return; GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if ((GV.EVEX.b == 1) || (GV.MOD_ == 3)) GV.ERROR_OPCODE = UD_;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "v4fnmaddss ");
        #endif
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m128_xmm;
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

        index = (~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V;
        index = (index / 4) * 4;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic, RegistersAVX512[index]);
           i = strlen((char*) &(*pMyDisasm).Operand2.OpMnemonic);
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, "...");
           i+=3;
           (void) strcpy ((char*) (*pMyDisasm).Operand2.OpMnemonic+i, RegistersAVX512[index+3]);
        #endif

        (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand2.Registers.type = AVX512_REG;
        (*pMyDisasm).Operand2.Registers.zmm = REGS[index] + REGS[index+1] + REGS[index+2] + REGS[index+3];
        (*pMyDisasm).Operand2.OpSize = 512;

        MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub213ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub213sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 be
* ==================================================================== */

void __bea_callspec__ vfnmsub231ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub231ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub231pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 bf
* ==================================================================== */

void __bea_callspec__ vfnmsub231ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub231ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub231sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 b8
* ==================================================================== */

void __bea_callspec__ vfmadd231ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd231ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd231pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 a9
* ==================================================================== */

void __bea_callspec__ vfmadd213ss_(PDISASM pMyDisasm)
{
  /* ========== 0x66 */
  if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    GV.OperandSize = GV.OriginalOperandSize;
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    if (GV.VEX.state == InUsePrefix) {
     if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd213ss ");
       #endif
     } else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd213sd ");
       #endif

     }
     ArgsVEX(pMyDisasm);
    } else {
     FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
*      0x 0f 38 af
* ==================================================================== */

void __bea_callspec__ vfnmsub213ss_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub213ss ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfnmsub213sd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 93
*      VGATHERQPS xmm1 {k1}, vm64x
* ==================================================================== */

void __bea_callspec__ vgatherqps_(PDISASM pMyDisasm)
{
 /* ========== 0x66 */
 if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   if (GV.VEX.state == InUsePrefix) {
     if (
         ((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
       ) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgatherqps ");
       #endif
       GV.EVEX.masking = MERGING;
       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2qword;
           GxExVEX(pMyDisasm);

         }
         else {
           GV.MemDecoration = Arg2qword;
           GxEx(pMyDisasm);
         }

       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;

         if (GV.EVEX.state != InUsePrefix) {
           GV.Register_ = SSE_REG;
           GV.MemDecoration = Arg2qword;
           GxExVEX(pMyDisasm);


         }
         else {
           GV.Register_ = SSE_REG;
           GV.MemDecoration = Arg2qword;
           GxEx(pMyDisasm);

         }
       }
       else if (GV.EVEX.LL == 0x2) {
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX_REG;
         GV.MemDecoration = Arg2qword;
         GxEx(pMyDisasm);

       }

     } else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vgatherqpd ");
       #endif
       GV.EVEX.masking = MERGING;
       GV.MemDecoration = Arg2qword;
       if (GV.VEX.L == 0) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         GV.VSIB_ = SSE_REG;
         GV.Register_ = SSE_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GxExVEX(pMyDisasm);

         }
         else {
           GxEx(pMyDisasm);
         }

       }
       else if (GV.VEX.L == 0x1) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
         GV.VSIB_ = AVX_REG;
         GV.Register_ = AVX_REG;
         if (GV.EVEX.state != InUsePrefix) {
           GV.MemDecoration = Arg2dword;
           GxExVEX(pMyDisasm);

         }
         else {
           GV.MemDecoration = Arg2qword;
           GxEx(pMyDisasm);
         }

       }
       else if (GV.EVEX.LL == 0x2) {
         GV.EVEX.tupletype = TUPLE1_SCALAR;
         (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
         GV.VSIB_ = AVX512_REG;
         GV.Register_ = AVX512_REG;
         GV.MemDecoration = Arg2qword;
         GxEx(pMyDisasm);

       }
     }
   } else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 96
* ==================================================================== */

void __bea_callspec__ vfmaddsub132ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmaddsub132ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmaddsub132pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 a8
* ==================================================================== */

void __bea_callspec__ vfmadd213ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd213ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmadd213pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f 38 ba
* ==================================================================== */

void __bea_callspec__ vfmsub231ps_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         if (((GV.REX.W_ == 0x0) && (GV.EVEX.state != InUsePrefix)) || ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub231ps ");
           #endif
         } else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfmsub231pd ");
           #endif

         }
         ArgsVEX(pMyDisasm);
       } else {
         FailDecode(pMyDisasm);
       }
   }
   else {
       FailDecode(pMyDisasm);
   }
}



/* ====================================================================
*      0x 0f d3
* ==================================================================== */

void __bea_callspec__ psrlq_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsrlq ", "psrlq ", MEM128);
}

/* ====================================================================
*      0x 0f d1
* ==================================================================== */

void __bea_callspec__ psrlw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsrlw ", "psrlw ", MEM128);
}

/* ====================================================================
*      0x 0f 75
* ==================================================================== */

void __bea_callspec__ pcmpeqw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpcmpeqw ", "pcmpeqw ", FULL_MEM);
}

/* ====================================================================
*      0x 0f d8
* ==================================================================== */

void __bea_callspec__ psubusb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubusb ", "psubusb ", FULL_MEM);
}

/* ====================================================================
*      0x 0f eb
* ==================================================================== */

void __bea_callspec__ por_(PDISASM pMyDisasm)
{

 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 1) {
     if (GV.EVEX.state == InUsePrefix) {
       if (GV.EVEX.W == 0) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpord ");
         #endif
       }
       else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vporq ");
         #endif
       }
       GV.EVEX.tupletype = FULL;
     }
     else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpor ");
       #endif
     }
     ArgsVEX(pMyDisasm);
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "por ");
       #endif
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "por ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);
   }
 }

}

/* ====================================================================
*      0x 0f d9
* ==================================================================== */

void __bea_callspec__ psubusw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubusw ", "psubusw ", FULL_MEM);
}

/* ====================================================================
*      0x 0f 74
* ==================================================================== */

void __bea_callspec__ pcmpeqb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpcmpeqb ", "pcmpeqb ", FULL);
}

/* ====================================================================
*      0x 0f 76
* ==================================================================== */

void __bea_callspec__ pcmpeqd_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpcmpeqd ", "pcmpeqd ", FULL);
}

/* ====================================================================
*      0x 0f d2
* ==================================================================== */

void __bea_callspec__ psrld_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsrld ", "psrld ", MEM128);
}

/* ====================================================================
*      0x 0f db
* ==================================================================== */

void __bea_callspec__ pand_block(PDISASM pMyDisasm, const char* mnemonic1, const char* mnemonic2, UInt8 tupletype)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic1);
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = tupletype;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic2);
        #endif
        GV.MemDecoration = Arg2_m128_xmm;
        GV.Register_ = SSE_REG;
        GxEx(pMyDisasm);

    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic2);
        #endif
        GV.Register_ = MMX_REG;
        GxEx(pMyDisasm);
    }
  }

}


/* ====================================================================
*      0x 0f db
* ==================================================================== */

void __bea_callspec__ pand_(PDISASM pMyDisasm)
{
   if (GV.VEX.state == InUsePrefix) {
     if (GV.VEX.pp == 1) {
       if (GV.EVEX.state == InUsePrefix) {
         if (GV.EVEX.W == 0) {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpandd ");
           #endif
         }
         else {
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpandq ");
           #endif
         }
         GV.EVEX.tupletype = FULL;
       }
       else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpand ");
         #endif
       }
       ArgsVEX(pMyDisasm);
     }
     else {
       FailDecode(pMyDisasm);
     }
   }
   else {
      /* ========== 0x66 */
      if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pand ");
        #endif
        GV.MemDecoration = Arg2_m128_xmm;
        GV.Register_ = SSE_REG;
        GxEx(pMyDisasm);
      }
      else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pand ");
        #endif
        GV.Register_ = MMX_REG;
        GxEx(pMyDisasm);
      }
   }
}

/* ====================================================================
*      0x 0f fa
* ==================================================================== */

void __bea_callspec__ psubd_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubd ", "psubd ", FULL);
}


/* ====================================================================
*      0x 0f ee
* ==================================================================== */

void __bea_callspec__ pmaxsw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpmaxsw ", "pmaxsw ", FULL_MEM);
}

/* ====================================================================
*      0x 0f 69
* ==================================================================== */

void __bea_callspec__ punpckhwd_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpckhwd ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhwd ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);
       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhwd ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);

   }
}

/* ====================================================================
*      0x 0f 6c
* ==================================================================== */

void __bea_callspec__ punpcklqdq_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpcklqdq ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklqdq ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklqdq ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);

   }
}





/* ====================================================================
*      0x 0f 6a
* ==================================================================== */

void __bea_callspec__ punpckhdq_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpckhdq ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhdq ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhdq ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);

   }
}





/* ====================================================================
*      0x 0f e4
* ==================================================================== */

void __bea_callspec__ pmulhuw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpmulhuw ", "pmulhuw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f 62
* ==================================================================== */

void __bea_callspec__ punpckldq_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpckldq ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckldq ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);
       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckldq ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);
   }
}

/* ====================================================================
*      0x 0f ed
* ==================================================================== */

void __bea_callspec__ paddsw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddsw ", "paddsw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f e1
* ==================================================================== */

void __bea_callspec__ psraw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsraw ", "psraw ", MEM128);
}

/* ====================================================================
*      0x 0f df
* ==================================================================== */

void __bea_callspec__ pandn_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 1) {
     if (GV.EVEX.state == InUsePrefix) {
       if (GV.EVEX.W == 0) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpandnd ");
         #endif
       }
       else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpandnq ");
         #endif
       }
       GV.EVEX.tupletype = FULL;
     }
     else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpandn ");
       #endif
     }
     ArgsVEX(pMyDisasm);
   }
   else {
     FailDecode(pMyDisasm);
   }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pandn ");
      #endif
      GV.MemDecoration = Arg2_m128_xmm;
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2qword;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pandn ");
      #endif
      GV.Register_ = MMX_REG;
      GxEx(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f e2
* ==================================================================== */

void __bea_callspec__ psrad_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsrad ", "psrad ", MEM128);
}


/* ====================================================================
*      0x 0f e5
* ==================================================================== */

void __bea_callspec__ pmulhw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpmulhw ", "pmulhw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f 67
* ==================================================================== */

void __bea_callspec__ packuswb_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpackuswb ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packuswb ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packuswb ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);

   }
}





/* ====================================================================
*      0x 0f f4
* ==================================================================== */

void __bea_callspec__ pmuludq_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpmuludq ", "pmuludq ", FULL_MEM);
}


/* ====================================================================
*      0x 0f e9
* ==================================================================== */

void __bea_callspec__ psubsw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubsw ", "psubsw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f 6d
* ==================================================================== */

void __bea_callspec__ punpckhqdq_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpckhqdq ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhqdq ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhqdq ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);

   }
}

/* ====================================================================
*      0x 0f f8
* ==================================================================== */

void __bea_callspec__ psubb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubb ", "psubb ", FULL_MEM);
}


/* ====================================================================
*      0x 0f d5
* ==================================================================== */

void __bea_callspec__ pmullw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpmullw ", "pmullw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f f2
* ==================================================================== */

void __bea_callspec__ pslld_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpslld ", "pslld ", MEM128);
}


/* ====================================================================
*      0x 0f 6b
* ==================================================================== */

void __bea_callspec__ packssdw_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpackssdw ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packssdw ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packssdw ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);

   }
}

/* ====================================================================
*      0x 0f f9
* ==================================================================== */

void __bea_callspec__ psubw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubw ", "psubw ", FULL);
}

/* ====================================================================
*      0x 0f 63
* ==================================================================== */

void __bea_callspec__ packsswb_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpacksswb ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packsswb ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);
       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packsswb ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);
   }
}

/* ====================================================================
*      0x 0f fb
* ==================================================================== */

void __bea_callspec__ psubq_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubq ", "psubq ", FULL);
}


/* ====================================================================
*      0x 0f e8
* ==================================================================== */

void __bea_callspec__ psubsb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsubsb ", "psubsb ", FULL_MEM);
}


/* ====================================================================
*      0x 0f f1
* ==================================================================== */

void __bea_callspec__ psllw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsllw ", "psllw ", MEM128);
}


/* ====================================================================
*      0x 0f f3
* ==================================================================== */

void __bea_callspec__ psllq_(PDISASM pMyDisasm)
{
 pand_block(pMyDisasm, "vpsllq ", "psllq ", MEM128);
}


/* ====================================================================
*      0x 0f da
* ==================================================================== */

void __bea_callspec__ pminub_(PDISASM pMyDisasm)
{
 pand_block(pMyDisasm, "vpminub ", "pminub ", FULL_MEM);
}


/* ====================================================================
*      0x 0f fe
* ==================================================================== */

void __bea_callspec__ paddd_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddd ", "paddd ", FULL);
}


/* ====================================================================
*      0x 0f fc
* ==================================================================== */

void __bea_callspec__ paddb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddb ", "paddb ", FULL_MEM);
}


/* ====================================================================
*      0x 0f 65
* ==================================================================== */

void __bea_callspec__ pcmpgtw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpcmpgtw ", "pcmpgtw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f e3
* ==================================================================== */

void __bea_callspec__ pavgw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpavgw ", "pavgw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f fd
* ==================================================================== */

void __bea_callspec__ paddw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddw ", "paddw ", FULL_MEM);
}

/* ====================================================================
*      0x 0f 64
* ==================================================================== */

void __bea_callspec__ pcmpgtb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpcmpgtb ", "pcmpgtb ", FULL_MEM);
}


/* ====================================================================
*      0x 0f ef
* ==================================================================== */

void __bea_callspec__ pxor_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.state == InUsePrefix) {
        if (GV.EVEX.W == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpxord ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpxorq ");
          #endif
        }
        GV.EVEX.tupletype = FULL;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpxor ");
        #endif
      }
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pxor ");
        #endif
        GV.MemDecoration = Arg2_m128_xmm;
        GV.Register_ = SSE_REG;
        GxEx(pMyDisasm);

    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pxor ");
        #endif
        GV.Register_ = MMX_REG;
        GxEx(pMyDisasm);
    }
  }

}

/* ====================================================================
*      0x 0f 66
* ==================================================================== */

void __bea_callspec__ pcmpgtd_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpcmpgtd ", "pcmpgtd ", FULL);
}


/* ====================================================================
*      0x 0f de
* ==================================================================== */

void __bea_callspec__ pmaxub_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpmaxub ", "pmaxub ", FULL_MEM);
}


/* ====================================================================
*      0x 0f d4
* ==================================================================== */

void __bea_callspec__ paddq_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddq ", "paddq ", FULL);
}


/* ====================================================================
*      0x 0f ec
* ==================================================================== */

void __bea_callspec__ paddsb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddsb ", "paddsb ", FULL_MEM);
}

/* ====================================================================
*      0x 0f 68
* ==================================================================== */

void __bea_callspec__ punpckhbw_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpckhbw ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhbw ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);
       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhbw ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);
   }
}

/* ====================================================================
*      0x 0f f5
* ==================================================================== */

void __bea_callspec__ pmaddwd_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpmaddwd ", "pmaddwd ", FULL_MEM);
}


/* ====================================================================
*      0x 0f e0
* ==================================================================== */

void __bea_callspec__ pavgb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpavgb ", "pavgb ", FULL_MEM);
}


/* ====================================================================
*      0x 0f dd
* ==================================================================== */

void __bea_callspec__ paddusw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddusw ", "paddusw ", FULL_MEM);
}

/* ====================================================================
*      0x 0f dc
* ==================================================================== */

void __bea_callspec__ paddusb_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpaddusb ", "paddusb ", FULL_MEM);
}

/* ====================================================================
*      0x 0f 60
* ==================================================================== */

void __bea_callspec__ punpcklbw_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpcklbw ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklbw ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
       GV.MemDecoration = Arg2qword;
       (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklbw ");
       #endif
       GV.Register_ = MMX_REG;
       GxEx(pMyDisasm);

   }
}

/* ====================================================================
*      0x 0f f6
* ==================================================================== */

void __bea_callspec__ psadbw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpsadbw ", "psadbw ", FULL_MEM);
}

/* ====================================================================
*      0x 0f 61
* ==================================================================== */

void __bea_callspec__ punpcklwd_(PDISASM pMyDisasm)
{
   /* ========== 0x66 */
   if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       GV.OperandSize = GV.OriginalOperandSize;
       (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
       (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION;
       if (GV.VEX.state == InUsePrefix) {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpunpcklwd ");
         #endif
         if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
         ArgsVEX(pMyDisasm);
       } else {
         #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklwd ");
         #endif
         GV.MemDecoration = Arg2_m128_xmm;
         GV.Register_ = SSE_REG;
         GxEx(pMyDisasm);

       }
   }
   else {
    GV.MemDecoration = Arg2qword;
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklwd ");
    #endif
    GV.Register_ = MMX_REG;
    GxEx(pMyDisasm);
   }
}

/* ====================================================================
*      0x 0f ea
* ==================================================================== */

void __bea_callspec__ pminsw_(PDISASM pMyDisasm)
{
  pand_block(pMyDisasm, "vpminsw ", "pminsw ", FULL_MEM);
}


/* ====================================================================
*      0x 0f 5c
* ==================================================================== */
void __bea_callspec__ subps_VW(PDISASM pMyDisasm)
{
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
      if (GV.VEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
        (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsubsd ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3qword;
        GyEy(pMyDisasm);
      }
      else {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subsd ");
        #endif
        GV.Register_ = SSE_REG;
        GxEx(pMyDisasm);
      }
   }
   /* ========= 0xf3 */
   else if (GV.PrefRepe == 1) {
       if (GV.VEX.state == InUsePrefix) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsubss ");
        #endif
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3dword;
        GyEy(pMyDisasm);
       }
       else {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subss ");
        #endif
        GV.Register_ = SSE_REG;
        GxEx(pMyDisasm);
       }
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsubpd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           ArgsVEX(pMyDisasm);
       }
       else {
           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128d_xmm;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subpd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
       }
  }
  else {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsubps ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
      ArgsVEX(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 5f
* ==================================================================== */
void __bea_callspec__ maxps_VW(PDISASM pMyDisasm)
{
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaxsd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);
           GV.MemDecoration = Arg3qword;
       }
       else {
           (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2qword;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxsd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
       }
   }
   /* ========= 0xf3 */
   else if (GV.PrefRepe == 1) {
       if (GV.VEX.state == InUsePrefix) {
         (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
         (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaxss ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);
           GV.MemDecoration = Arg3dword;
       }
       else {
           (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2dword;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxss ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
       }
   }
   /* ========== 0x66 */
  else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaxpd ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
      ArgsVEX(pMyDisasm);
    }
    else {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128d_xmm;
      (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxpd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
   }
  else {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
      (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmaxps ");
      #endif
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
      ArgsVEX(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2_m128_xmm;
      (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxps ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
  }
}


/* ====================================================================
*      0x 0f 5d
* ==================================================================== */
void __bea_callspec__ minps_VW(PDISASM pMyDisasm)
{
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vminsd ");
           #endif

           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);

           GV.MemDecoration = Arg3qword;

       }
       else {
           (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2qword;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minsd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
       }
   }
   /* ========= 0xf3 */
   else if (GV.PrefRepe == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vminss ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);
           GV.MemDecoration = Arg3dword;
       }
       else {
           (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2dword;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minss ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vminpd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           ArgsVEX(pMyDisasm);

       }
       else {
           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128d_xmm;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minpd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
   else {

       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vminps ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           ArgsVEX(pMyDisasm);
       }
       else {

           GV.MemDecoration = Arg2_m128_xmm;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minps ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
}


/* ====================================================================
*      0x 0f 59
* ==================================================================== */
void __bea_callspec__ mulps_VW(PDISASM pMyDisasm)
{
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmulsd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);

           GV.MemDecoration = Arg3qword;

       }
       else {
           (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2qword;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulsd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
   /* ========= 0xf3 */
   else if (GV.PrefRepe == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmulss ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);
           GV.MemDecoration = Arg3dword;
       }
       else {
           (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2dword;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulss ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
       }
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmulpd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           ArgsVEX(pMyDisasm);
       }
       else {
           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128d_xmm;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulpd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
   else {

       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmulps ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           ArgsVEX(pMyDisasm);
       }
       else {

           GV.MemDecoration = Arg2_m128_xmm;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulps ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
}


/* ====================================================================
*      0x 0f 5e
* ==================================================================== */
void __bea_callspec__ divps_VW(PDISASM pMyDisasm)
{
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vdivsd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);

           GV.MemDecoration = Arg3qword;

       }
       else {
           (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2qword;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divsd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
   /* ========= 0xf3 */
   else if (GV.PrefRepe == 1) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vdivss ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           GV.Register_ = SSE_REG;
           GyEy(pMyDisasm);
           GV.MemDecoration = Arg3dword;
       }
       else {
           (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
           GV.MemDecoration = Arg2dword;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divss ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);
       }
   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vdivpd ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           ArgsVEX(pMyDisasm);
       }
       else {
           GV.OperandSize = GV.OriginalOperandSize;
           (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
           GV.MemDecoration = Arg2_m128d_xmm;
           (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divpd ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
   else {

       if (GV.VEX.state == InUsePrefix) {
           (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
           (*pMyDisasm).Instruction.Category += ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vdivps ");
           #endif
           if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
           if ((GV.VEX.opcode == 0xc4) && (GV.REX.W_ == 0x1)) GV.OperandSize = 64;
           ArgsVEX(pMyDisasm);
       }
       else {

           GV.MemDecoration = Arg2_m128_xmm;
           (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
           #ifndef BEA_LIGHT_DISASSEMBLY
              (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divps ");
           #endif
           GV.Register_ = SSE_REG;
           GxEx(pMyDisasm);

       }
   }
}



/* ====================================================================
*      0x 0f 38 20
* ==================================================================== */
void __bea_callspec__ pmovsxbw_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsxbw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovswb ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbw ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 21
* ==================================================================== */
void __bea_callspec__ pmovsxbd_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsxbd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = QUARTER_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsdb ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = QUARTER_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbd ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 22
* ==================================================================== */
void __bea_callspec__ pmovsxbq_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsxbq ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = EIGHTH_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsqb ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = EIGHTH_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       GV.EVEX.tupletype = EIGHTH_MEM;
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbq ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 23
* ==================================================================== */
void __bea_callspec__ pmovsxwd_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsxwd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsdw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxwd ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 24
* ==================================================================== */
void __bea_callspec__ pmovsxwq_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsxwq ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsqw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxwq ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 25
* ==================================================================== */
void __bea_callspec__ pmovsxdq_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsxdq ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovsqd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxdq ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 30
* ==================================================================== */
void __bea_callspec__ pmovzxbw_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovzxbw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovwb ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbw ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 31
* ==================================================================== */
void __bea_callspec__ pmovzxbd_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovzxbd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = QUARTER_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovdb ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = QUARTER_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbd ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 32
* ==================================================================== */
void __bea_callspec__ pmovzxbq_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovzxbq ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = EIGHTH_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovqb ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = EIGHTH_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbq ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 33
* ==================================================================== */
void __bea_callspec__ pmovzxwd_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovzxwd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovdw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxwd ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 34
* ==================================================================== */
void __bea_callspec__ pmovzxwq_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovzxwq ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = QUARTER_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);
     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovqw ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = QUARTER_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);

     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxwq ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}



/* ====================================================================
*      0x 0f 38 35
* ==================================================================== */
void __bea_callspec__ pmovzxdq_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0x1) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovzxdq ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg2qword;
       GxEx(pMyDisasm);

     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg2_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg2_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else if (GV.VEX.pp == 0x2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmovqd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = HALF_MEM;
     if (GV.VEX.L == 0) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
       GV.Register_ = SSE_REG;
       GV.MemDecoration = Arg1qword;
       ExGx(pMyDisasm);

     }
     else if (GV.VEX.L == 0x1) {
       (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
       GV.MemDecoration = Arg1_m128_xmm;
       GV.Register_ = SSE_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.Register_ = AVX_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
     else if (GV.EVEX.LL == 0x2) {
       (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
       GV.MemDecoration = Arg1_m256_ymm;
       GV.Register_ = AVX_REG;
       MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);

       GV.Register_ = AVX512_REG;
       Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);

       GV.EIP_ += GV.DECALAGE_EIP+2;
     }
   }
   else {
     FailDecode(pMyDisasm);
   }

 }
 else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
   GV.OperandSize = GV.OriginalOperandSize;
   (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
   GV.MemDecoration = Arg2qword;
   (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxdq ");
   #endif
   GV.Register_ = SSE_REG;
   GxEx(pMyDisasm);

 }
 else {
   FailDecode(pMyDisasm);
 }
}


/* ====================================================================
*      0x 0f 51
* ==================================================================== */
void __bea_callspec__ sqrtps_VW(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 1) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 0)
     ) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsqrtpd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
     ArgsVEX_GxEx(pMyDisasm);
   }
   else if (GV.VEX.pp == 0) {
     if (
       (GV.EVEX.state == InUsePrefix) &&
       (GV.EVEX.W == 1)
     ) {
       FailDecode(pMyDisasm);
       return;
     }
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsqrtps ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
     ArgsVEX_GxEx(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsqrtss ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX_INSTRUCTION;
     GV.Register_ = SSE_REG;
     GV.MemDecoration = Arg2dword;
     GxEx(pMyDisasm);
   }
   else if (GV.VEX.pp == 3) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vsqrtsd ");
     #endif
     if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
     (*pMyDisasm).Instruction.Category = (GV.EVEX.state == InUsePrefix) ? AVX512_INSTRUCTION : AVX2_INSTRUCTION;
     GV.Register_ = SSE_REG;
     GV.MemDecoration = Arg2qword;
     GxEx(pMyDisasm);
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========= 0xf2 */
   if (GV.PrefRepne == 1) {
     (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
     GV.MemDecoration = Arg2qword;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtsd ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   /* ========= 0xf3 */
   else if (GV.PrefRepe == 1) {
     (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
     GV.MemDecoration = Arg2dword;
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtss ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   /* ========== 0x66 */
   else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
     GV.OperandSize = GV.OriginalOperandSize;
     (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtpd ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   else {
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtps ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
 }

}



/* ====================================================================
*      0x 0f 52
* ==================================================================== */
void __bea_callspec__ rsqrtps_(PDISASM pMyDisasm)
{
 if (GV.EVEX.state == InUsePrefix) {
   FailDecode(pMyDisasm);
 }
 else if (GV.VEX.state == InUsePrefix) {

   if (GV.VEX.pp == 0) {
     (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrtps ");
     #endif
     ArgsVEX_GxEx(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrtss ");
     #endif
     GV.MemDecoration = Arg3dword;
     GV.Register_ = SSE_REG;
     GyEy(pMyDisasm);

   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0xf3 */
   if (GV.PrefRepe == 1) {
     (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
     GV.MemDecoration = Arg2dword;
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rsqrtss ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
   else {
     GV.MemDecoration = Arg2_m128_xmm;
     (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rsqrtps ");
     #endif
     GV.Register_ = SSE_REG;
     GxEx(pMyDisasm);

   }
 }

}


/* ====================================================================
*      0x 0f 53
* ==================================================================== */
void __bea_callspec__ rcpps_(PDISASM pMyDisasm)
{
 if (GV.EVEX.state == InUsePrefix) {
   FailDecode(pMyDisasm);
 }
 else if (GV.VEX.state == InUsePrefix) {
   if (GV.VEX.pp == 0) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcpps ");
     #endif
     ArgsVEX_GxEx(pMyDisasm);
   }
   else if (GV.VEX.pp == 2) {
     #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcpss ");
     #endif
     ArgsVEX_GxEx(pMyDisasm);
   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   /* ========== 0xf3 */
   if (GV.PrefRepe == 1) {
       (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
       GV.MemDecoration = Arg2dword;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rcpss ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
   else {
       GV.MemDecoration = Arg2_m128_xmm;
       (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rcpps ");
       #endif
       GV.Register_ = SSE_REG;
       GxEx(pMyDisasm);

   }
 }
}

void __bea_callspec__ emms_(PDISASM pMyDisasm)
{
 if (GV.VEX.state == InUsePrefix) {
   if (GV.EVEX.state == InUsePrefix) {
     FailDecode(pMyDisasm);
     return;
   }
   if (GV.VEX.pp == 0) {
     (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION;
     if (
         ((GV.EVEX.state != InUsePrefix) && (GV.VEX.vvvv != 15)) ||
         ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.vvvv != 15))
       ) {
       GV.ERROR_OPCODE = UD_;
     }
     if (GV.VEX.L == 0) {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vzeroupper ");
       #endif
       GV.EIP_++;
     }
     else {
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vzeroall ");
       #endif
       GV.EIP_++;
     }
     (*pMyDisasm).Instruction.ImplicitModifiedRegs.type = AVX_REG;
     (*pMyDisasm).Instruction.ImplicitModifiedRegs.ymm = REG0 + REG1
      + REG2 + REG3 + REG4 + REG5 + REG6 + REG7 + REG8 + REG9 + REG10 + REG11
      + REG12 + REG13 + REG14 + REG15;

   }
   else {
     FailDecode(pMyDisasm);
   }
 }
 else {
   (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+STATE_MANAGEMENT;
   #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "emms ");
   #endif
   /* x87 FPU Tag is zeroed */
   GV.EIP_++;
 }
}

/* ====================================================================
*      0x 0f 7e
* ==================================================================== */
void __bea_callspec__ movd_EP(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION+DATA_TRANSFER;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+DATA_TRANSFER;
      }
      if (
        ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
        ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
        ) {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovd ");
        #endif
        GV.MemDecoration = Arg1dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovq ");
        #endif
        GV.MemDecoration = Arg1qword;
      }
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {

    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2qword;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
      #endif
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      if (GV.REX.W_ == 1) {
        GV.MemDecoration = Arg1qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
      }
      else {
        GV.MemDecoration = Arg1dword;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
        #endif
      }
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      if (GV.REX.W_ == 1) {
        GV.MemDecoration = Arg1qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
      }
      else {
        GV.MemDecoration = Arg1dword;
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
        #endif
      }
      MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
      GV.Register_ = MMX_REG;
      Reg_Opcode(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
  }
}


/* ====================================================================
*      0x 0f 6e
* ==================================================================== */
void __bea_callspec__ movd_PE(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION+DATA_TRANSFER;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+DATA_TRANSFER;
      }
      if (
        ((GV.EVEX.state != InUsePrefix) && (GV.REX.W_ == 0)) ||
        ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0))
        ) {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovd ");
        #endif
        GV.MemDecoration = Arg2dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovq ");
        #endif
        GV.MemDecoration = Arg2qword;
      }
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
     /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      if (GV.REX.W_ == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
        GV.MemDecoration = Arg2qword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
        #endif
        GV.MemDecoration = Arg2dword;
      }
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      if (GV.REX.W_ == 1) {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
      }
      else {
        GV.MemDecoration = Arg2dword;
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
        #endif
      }
      GV.Register_ = MMX_REG;
      GxEx(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f 6f
* ==================================================================== */
void __bea_callspec__ movq_PQ(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) {
        GV.EVEX.tupletype = FULL_MEM;
        if (GV.EVEX.W == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqa32 ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqa64 ");
          #endif
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqa ");
        #endif
      }
      ArgsVEX_GxEx(pMyDisasm);
    }
    else if (GV.VEX.pp == 2) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) {
        GV.EVEX.tupletype = FULL_MEM;
        if (GV.EVEX.W == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu32 ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu64 ");
          #endif
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu ");
        #endif
      }
      ArgsVEX_GxEx(pMyDisasm);
    }
    else if (GV.VEX.pp == 3) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) {
        if (GV.EVEX.W == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu8 ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu16 ");
          #endif
        }
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX_GxEx(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION + DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqu ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqa ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2qword;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
      #endif
      GV.Register_ = MMX_REG;
      GxEx(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f 7f
* ==================================================================== */
void __bea_callspec__ movq_QP(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) {
        if (GV.EVEX.W == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqa32 ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqa64 ");
          #endif
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqa ");
        #endif
      }
      ArgsVEX_ExGx(pMyDisasm);
    }
    else if (GV.VEX.pp == 2) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) {
        if (GV.EVEX.W == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu32 ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu64 ");
          #endif
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu ");
        #endif
      }
      ArgsVEX_ExGx(pMyDisasm);
    }
    else if (GV.VEX.pp == 3) {
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) {
        if (GV.EVEX.W == 0) {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu8 ");
          #endif
        }
        else {
          #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovdqu16 ");
          #endif
        }
        ArgsVEX_ExGx(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      GV.MemDecoration = Arg1_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqu ");
      #endif
      GV.Register_ = SSE_REG;
      ExGx(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg1_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqa ");
      #endif
      GV.Register_ = SSE_REG;
      ExGx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg1qword;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
      #endif
      GV.Register_ = MMX_REG;
      ExGx(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f d6
* ==================================================================== */
void __bea_callspec__ movq_WV(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (
      ((GV.EVEX.state == InUsePrefix) && (GV.EVEX.W == 0)) ||
      (GV.VEX.L != 0)
    ) {
      FailDecode(pMyDisasm);
      return;
    }
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmovq ");
      #endif
      if (GV.EVEX.state == InUsePrefix) {
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION+DATA_TRANSFER;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
      }
      else {
        (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION+DATA_TRANSFER;
      }
      GV.MemDecoration = Arg1dword;
      GV.Register_ = SSE_REG;
      ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
      if (!Security(1, pMyDisasm)) return;
      GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_ != 0x3){
        FailDecode(pMyDisasm);
        return;
      }
      (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2dqword;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdq2q ");
      #endif
      GV.Register_ = MMX_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

      GV.Register_ = SSE_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_+= GV.DECALAGE_EIP+2;

    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
      if (!Security(1, pMyDisasm)) return;
      GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
      if (GV.MOD_ != 0x3){
        FailDecode(pMyDisasm);
        return;
      }
      (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
      GV.MemDecoration = Arg2qword;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq2dq ");
      #endif
      GV.Register_ = SSE_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);

      GV.Register_ = MMX_REG;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg1qword;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
      #endif
      GV.Register_ = SSE_REG;
      ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }

}


/* ====================================================================
*      0x 0f 38 1c
* ==================================================================== */
void __bea_callspec__ pabsb_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpabsb ");
      #endif
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      GV.Register_ = SSE_REG;
    }
    else {
      GV.MemDecoration = Arg2qword;
      GV.Register_ = MMX_REG;
    }
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsb ");
    #endif
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 1f
* ==================================================================== */
void __bea_callspec__ vpabsq_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpabsq ");
      #endif
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 79
* ==================================================================== */
void __bea_callspec__ vpbroadcastw(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastw ");
        #endif
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2word, Arg2word, Arg2word, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 8e
* ==================================================================== */
void __bea_callspec__ vpmaskmovd2(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.REX.W_ == 0) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaskmovd ");
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaskmovq ");
      #endif
    }
    ArgsVEX_EyGy(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 38 8c
* ==================================================================== */
void __bea_callspec__ vpmaskmovd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.REX.W_ == 0) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaskmovd ");
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmaskmovq ");
      #endif
    }
    ArgsVEX(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
*      0x 0f 38 7f
* ==================================================================== */
void __bea_callspec__ vpermt2ps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermt2ps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermt2pd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 7e
* ==================================================================== */
void __bea_callspec__ vpermt2d(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermt2d ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermt2q ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 7d
* ==================================================================== */
void __bea_callspec__ vpermt2b(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermt2b ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermt2w ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 7c
* ==================================================================== */
void __bea_callspec__ vpbroadcastd2(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastd ");
        #endif
        GV.OperandSize = 32;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastq ");
        #endif
        GV.OperandSize = 64;
      }
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
      }
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 7b
* ==================================================================== */
void __bea_callspec__ vpbroadcastw2(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastw ");
        #endif
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        if (GV.VEX.L == 0) {
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.Register_ = AVX512_REG;
        }
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.Register_ = 0;
        GV.OperandSize = 16;
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 7a
* ==================================================================== */
void __bea_callspec__ vpbroadcastb2(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastb ");
        #endif
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        GV.EVEX.tupletype = TUPLE1_SCALAR;
        (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
        if (GV.VEX.L == 0) {
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.Register_ = AVX512_REG;
        }
        Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
        GV.Register_ = 0;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
        if (GV.MOD_ != 3) GV.ERROR_OPCODE = UD_;
        GV.EIP_ += GV.DECALAGE_EIP+2;
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 78
* ==================================================================== */
void __bea_callspec__ vpbroadcastb(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastb ");
        #endif
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2byte, Arg2byte, Arg2byte, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 18
* ==================================================================== */
void __bea_callspec__ vbroadcastss(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastss ");
        #endif
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2dword, Arg2dword, Arg2dword, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 58
* ==================================================================== */
void __bea_callspec__ vpbroadcastd(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastd ");
        #endif
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2dword, Arg2dword, Arg2dword, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 1b
* ==================================================================== */
void __bea_callspec__ vbroadcastf32(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastf32x8 ");
        #endif
        if (GV.VEX.L < 2) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE8;
        ArgsVEX_GE(pMyDisasm, Arg2_m256_ymm, Arg2_m256_ymm, Arg2_m256_ymm, SSE_REG, AVX_REG, AVX512_REG);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastf64x4 ");
        #endif
        if (GV.VEX.L < 2) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE4;
        ArgsVEX_GE(pMyDisasm, Arg2_m256_ymm, Arg2_m256_ymm, Arg2_m256_ymm, SSE_REG, AVX_REG, AVX512_REG);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 1a
* ==================================================================== */
void __bea_callspec__ vbroadcastf128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastf32x4 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE4;
        ArgsVEX_GE(pMyDisasm, Arg2_m128_xmm, Arg2_m128_xmm, Arg2_m128_xmm, SSE_REG, AVX_REG, AVX512_REG);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastf64x2 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE2;
        ArgsVEX_GE(pMyDisasm, Arg2_m128_xmm, Arg2_m128_xmm, Arg2_m128_xmm, SSE_REG, AVX_REG, AVX512_REG);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastf128 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2_m128_xmm, Arg2_m128_xmm, Arg2_m128_xmm, SSE_REG, AVX_REG, AVX512_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 19
* ==================================================================== */
void __bea_callspec__ vbroadcastsd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastf32x2 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE2;
        ArgsVEX_GE(pMyDisasm, Arg2qword, Arg2qword, Arg2qword, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastsd ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2qword, Arg2qword, Arg2qword, SSE_REG, SSE_REG, SSE_REG);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcastsd ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2qword, Arg2qword, Arg2qword, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 5b
* ==================================================================== */
void __bea_callspec__ vbroadcasti32x8(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcasti32x8 ");
        #endif
        if (GV.VEX.L < 2) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE8;
        ArgsVEX_GE(pMyDisasm, Arg2_m256_ymm, Arg2_m256_ymm, Arg2_m256_ymm, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcasti64x4 ");
        #endif
        if (GV.VEX.L < 2) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE4;
        ArgsVEX_GE(pMyDisasm, Arg2_m256_ymm, Arg2_m256_ymm, Arg2_m256_ymm, SSE_REG, SSE_REG, SSE_REG);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 5a
* ==================================================================== */
void __bea_callspec__ vbroadcasti128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcasti32x4 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE4;
        ArgsVEX_GE(pMyDisasm, Arg2_m128_xmm, Arg2_m128_xmm, Arg2_m128_xmm, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcasti64x2 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE2;
        ArgsVEX_GE(pMyDisasm, Arg2_m128_xmm, Arg2_m128_xmm, Arg2_m128_xmm, SSE_REG, SSE_REG, SSE_REG);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcasti128 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2_m128_xmm, Arg2_m128_xmm, Arg2_m128_xmm, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 59
* ==================================================================== */
void __bea_callspec__ vpbroadcastq(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vbroadcasti32x2 ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE2;
        ArgsVEX_GE(pMyDisasm, Arg2qword, Arg2qword, Arg2qword, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastq ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2qword, Arg2qword, Arg2qword, SSE_REG, SSE_REG, SSE_REG);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpbroadcastq ");
        #endif
        if (GV.VEX.L == 0) GV.ERROR_OPCODE = UD_;
        if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
        if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = TUPLE1_SCALAR;
        ArgsVEX_GE(pMyDisasm, Arg2qword, Arg2qword, Arg2qword, SSE_REG, SSE_REG, SSE_REG);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 1e
* ==================================================================== */
void __bea_callspec__ pabsd_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpabsd ");
      #endif
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsd ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2qword;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsd ");
      #endif
      GV.Register_ = MMX_REG;
      GxEx(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f 38 1d
* ==================================================================== */
void __bea_callspec__ pabsw_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpabsw ");
      #endif
      if (GV.VEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.state == InUsePrefix) GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128_xmm;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsw ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
    }
    else {
      GV.MemDecoration = Arg2qword;
      #ifndef BEA_LIGHT_DISASSEMBLY
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsw ");
      #endif
      GV.Register_ = MMX_REG;
      GxEx(pMyDisasm);
    }
  }
}

/* ====================================================================
*      0x 0f 38 c8
* ==================================================================== */
void __bea_callspec__ sha1nexte_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (
      (GV.EVEX.pp == 1) &&
      (GV.EVEX.LL == 2)
    ) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.EVEX.tupletype = FULL;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vexp2ps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vexp2pd ");
        #endif
      }
      GV.MemDecoration = Arg2_m512_zmm;
      GV.Register_ = AVX512_REG;
      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = SHA_INSTRUCTION;
    GV.MemDecoration = Arg2_m128_xmm;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sha1nexte ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 c9
* ==================================================================== */
void __bea_callspec__ sha1msg1_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = SHA_INSTRUCTION;
    GV.MemDecoration = Arg2_m128_xmm;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sha1msg1 ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 ca
* ==================================================================== */
void __bea_callspec__ sha1msg2_(PDISASM pMyDisasm)
{

  if (GV.EVEX.state == InUsePrefix) {
    if (
      (GV.EVEX.pp == 1) &&
      (GV.EVEX.LL == 2)
    ) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.EVEX.tupletype = FULL;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp28ps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp28pd ");
        #endif
      }
      GV.MemDecoration = Arg2_m512_zmm;
      GV.Register_ = AVX512_REG;
      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = SHA_INSTRUCTION;
    GV.MemDecoration = Arg2_m128_xmm;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sha1msg2 ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 cc
* ==================================================================== */
void __bea_callspec__ sha256msg1_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (
      (GV.EVEX.pp == 1) &&
      (GV.EVEX.LL == 2)
    ) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.EVEX.tupletype = FULL;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt28ps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt28pd ");
        #endif
      }
      GV.MemDecoration = Arg2_m512_zmm;
      GV.Register_ = AVX512_REG;
      GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = SHA_INSTRUCTION;
    GV.MemDecoration = Arg2_m128_xmm;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sha256msg1 ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 cd
* ==================================================================== */
void __bea_callspec__ sha256msg2_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (
      (GV.EVEX.pp == 1)
    ) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.EVEX.tupletype = FULL;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt28ss ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrsqrt28sd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.Register_ = SSE_REG;
      GyEy(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = SHA_INSTRUCTION;
    GV.MemDecoration = Arg2_m128_xmm;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sha256msg2 ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 cb
* ==================================================================== */
void __bea_callspec__ sha256rnd_(PDISASM pMyDisasm)
{

  if (GV.EVEX.state == InUsePrefix) {
    if (
      (GV.EVEX.pp == 1)
    ) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.EVEX.tupletype = FULL;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp28ss ");
        #endif
        GV.MemDecoration = Arg3dword;
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
          (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrcp28sd ");
        #endif
        GV.MemDecoration = Arg3qword;
      }
      GV.Register_ = SSE_REG;
      GyEy(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else if (GV.VEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  else {
    (*pMyDisasm).Instruction.Category = SHA_INSTRUCTION;
    GV.MemDecoration = Arg2_m128_xmm;
    #ifndef BEA_LIGHT_DISASSEMBLY
      (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sha256rnds2 ");
    #endif
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
    (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type =  SSE_REG;
    (*pMyDisasm).Operand1.Registers.xmm = REG0;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Operand3.OpMnemonic, RegistersSSE[0]);
    #endif
  }
}

/* ====================================================================
 *      0x 0f 38 db
 * ==================================================================== */
void __bea_callspec__ aesimc(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        if (GV.VEX.state == InUsePrefix) {
            (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaesimc ");
            #endif
            if (GV.VEX.vvvv != 15) {
              GV.ERROR_OPCODE = UD_;
            }
            GV.Register_ = SSE_REG;
            GV.MemDecoration = Arg2_m128i_xmm;
            GxEx(pMyDisasm);
        }
        else {
            GV.OperandSize = GV.OriginalOperandSize;
            (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
            GV.MemDecoration = Arg2_m128i_xmm;
            (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesimc ");
            #endif
            GV.Register_ = SSE_REG;
            GxEx(pMyDisasm);
            (*pMyDisasm).Operand2.OpSize = 128;
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 dc
 * ==================================================================== */
void __bea_callspec__ aesenc(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        if (GV.VEX.state == InUsePrefix) {
            (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaesenc ");
            #endif
            if (GV.VEX.vvvv != 15) {
              GV.ERROR_OPCODE = UD_;
            }
            GV.Register_ = SSE_REG;
            GV.MemDecoration = Arg3_m128i_xmm;
            GyEy(pMyDisasm);
        }
        else {
            GV.OperandSize = GV.OriginalOperandSize;
            (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
            GV.MemDecoration = Arg2_m128i_xmm;
            (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesenc ");
            #endif
            GV.Register_ = SSE_REG;
            GxEx(pMyDisasm);
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 dd
 * ==================================================================== */
void __bea_callspec__ aesenclast(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        if (GV.VEX.state == InUsePrefix) {
            (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaesenclast ");
            #endif
            if (GV.VEX.vvvv != 15) {
              GV.ERROR_OPCODE = UD_;
            }
            GV.Register_ = SSE_REG;
            GV.MemDecoration = Arg3_m128i_xmm;
            GyEy(pMyDisasm);
        }
        else {
            GV.OperandSize = GV.OriginalOperandSize;
            (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
            GV.MemDecoration = Arg2_m128i_xmm;
            (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesenclast ");
            #endif
            GV.Register_ = SSE_REG;
            GxEx(pMyDisasm);
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 de
 * ==================================================================== */
void __bea_callspec__ aesdec(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        if (GV.VEX.state == InUsePrefix) {
            (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaesdec ");
            #endif
            if (GV.VEX.vvvv != 15) {
              GV.ERROR_OPCODE = UD_;
            }
            GV.Register_ = SSE_REG;
            GV.MemDecoration = Arg3_m128i_xmm;
            GyEy(pMyDisasm);
        }
        else {
            GV.OperandSize = GV.OriginalOperandSize;
            (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
            GV.MemDecoration = Arg2_m128i_xmm;
            (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesdec ");
            #endif
            GV.Register_ = SSE_REG;
            GxEx(pMyDisasm);
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 df
 * ==================================================================== */
void __bea_callspec__ aesdeclast(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        if (GV.VEX.state == InUsePrefix) {
            (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaesdeclast ");
            #endif
            if (GV.VEX.vvvv != 15) {
              GV.ERROR_OPCODE = UD_;
            }
            GV.Register_ = SSE_REG;
            GV.MemDecoration = Arg3_m128i_xmm;
            GyEy(pMyDisasm);
        }
        else {
            GV.OperandSize = GV.OriginalOperandSize;
            (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
            GV.MemDecoration = Arg2_m128i_xmm;
            (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesdeclast ");
            #endif
            GV.Register_ = SSE_REG;
            GxEx(pMyDisasm);
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 3a df
 * ==================================================================== */
void __bea_callspec__ aeskeygen(PDISASM pMyDisasm)
{

  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
    return;
  }
  /* ========== 0x66 */
  if (GV.OperandSize == 16) {
    if (GV.VEX.state == InUsePrefix) {
      (*pMyDisasm).Instruction.Category = AVX_INSTRUCTION + AES_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vaeskeygenassist ");
      #endif

      GV.Register_ = SSE_REG;
      GV.MemDecoration = Arg2_m128i_xmm;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
    else {
      GV.OperandSize = GV.OriginalOperandSize;
      (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
      GV.MemDecoration = Arg2_m128i_xmm;
      (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aeskeygenassist ");
      #endif
      GV.Register_ = SSE_REG;
      GxEx(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }

}

/* ====================================================================
 *      0x 0f 3a 66
 * ==================================================================== */
void __bea_callspec__ vfpclassps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfpclassps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfpclasspd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 1) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}



/* ====================================================================
 *      0x 0f 3a 56
 * ==================================================================== */
void __bea_callspec__ vreduceps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vreduceps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vreducepd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 1) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
 *      0x 0f 3a 54
 * ==================================================================== */
void __bea_callspec__ vfixupmmps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfixupmmps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vfixupmmpd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 1) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
 *      0x 0f 3a 50
 * ==================================================================== */
void __bea_callspec__ vrangeps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrangeps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vrangepd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      if (GV.VEX.L == 1) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
 *      0x 0f 3a 46
 * ==================================================================== */
void __bea_callspec__ vperm2i128(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    FailDecode(pMyDisasm);
  }
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vperm2i128 ");
      #endif
      if (GV.VEX.L == 1) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
 *      0x 0f 3a 44
 * ==================================================================== */
void __bea_callspec__ pclmulqdq_(PDISASM pMyDisasm)
{
  if (GV.VEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpclmulqdq ");
      #endif
      if (GV.VEX.L == 1) GV.ERROR_OPCODE = UD_;
      ArgsVEX(pMyDisasm);
      getImmediat8(&(*pMyDisasm).Operand4, pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
    /* ========== 0x66 */
  else if (GV.OperandSize == 16) {
    (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
    GV.MemDecoration = Arg2_m128_xmm;
    (*pMyDisasm).Instruction.Category = CLMUL_INSTRUCTION;
    GV.Register_ = SSE_REG;
    GxEx(pMyDisasm);
    getImmediat8(&(*pMyDisasm).Operand3, pMyDisasm);
    if ((*pMyDisasm).Instruction.Immediat == 0) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmullqlqdq ");
      #endif
    }
    else if ((*pMyDisasm).Instruction.Immediat == 0x01 ) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulhqlqdq ");
        #endif
    }
    else if ((*pMyDisasm).Instruction.Immediat == 0x10 ) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmullqhqdq ");
        #endif
    }
    else if ((*pMyDisasm).Instruction.Immediat == 0x11 ) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulhqhqdq ");
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulqdq ");
        #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Operand3.OpMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Operand3.OpType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Operand3.OpSize = 8;
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ D8_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {
        GV.MemDecoration = Arg2dword;
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
            (*pMyDisasm).Operand1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
            (*pMyDisasm).Operand1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ D9_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldenv ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldcw ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstenv ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstcw ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnop ");
                #endif
            }
            else if (((MyMODRM & 0xf) >=0x8) && ((MyMODRM & 0xf) <=0xf)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp1 ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fchs ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fabs ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ftst ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxam ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld1 ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Operand2.OpSize = 80;

            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldl2t ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Operand2.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldl2e ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Operand2.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldpi ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Operand2.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldlg2 ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Operand2.OpSize = 80;
            }

            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldln2 ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Operand2.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldz ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand2.OpType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Operand2.OpSize = 80;
            }

            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "f2xm1 ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fyl2x ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fptan ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fpatan ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxtract ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fprem1 ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==6) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdecstp ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==7) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fincstp ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fprem ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fyl2xp1 ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsqrt ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsincos ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frndint ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fscale ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsin ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xf) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcos ");
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DA_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fiadd ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fimul ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficom ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
            (*pMyDisasm).Operand1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficomp ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
            (*pMyDisasm).Operand1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisub ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisubr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidiv ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidivr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovb ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmove ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovbe ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovu ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;

        }
        else if (MyMODRM == 0xe9) {
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucompp ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            (*pMyDisasm).Operand1.AccessMode = READ;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DB_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fist ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2tbyte;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1tbyte;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnb ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovne ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnbe ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnu ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand1.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {

            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fneni ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fndisi ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnclex ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fninit ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnsetpm ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frstpm ");
                #endif
            }
            else if (((MyMODRM & 0xf) >=0x8) && ((MyMODRM & 0xf) <=0xf)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomi ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand1.AccessMode = READ;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Operand2.OpSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0x0) && ((MyMODRM & 0xf) <=0x7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomi ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand1.OpSize = 80;
                (*pMyDisasm).Operand1.AccessMode = READ;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Operand2.OpSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else {
                FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DC_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
            (*pMyDisasm).Operand1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
            (*pMyDisasm).Operand1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
                #endif
                (*pMyDisasm).Operand1.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand2.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom2 ");
                #endif

            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp3 ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand2.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand2.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DD_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frstor ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 108*8;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsave ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REG0;
            (*pMyDisasm).Operand2.OpSize = 108*8;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstsw ");
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
            (*pMyDisasm).Operand2.OpSize = 16;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ffree ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch4 ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucom ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[0];
                (*pMyDisasm).Operand2.OpSize = 80;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomp ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Operand1.OpSize = 80;
            }

        }

        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DE_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fiadd ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fimul ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficom ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficomp ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisub ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisubr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidiv ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidivr ");
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REG0;
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "faddp ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmulp ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand2.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp5 ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Operand1.OpSize = 80;
            }
            else if (MyMODRM == 0xd9){
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcompp ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }


        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubrp ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubp ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand2.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivrp ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivp ");
                #endif
                (*pMyDisasm).Operand2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand2.Registers.type = FPU_REG;
  (*pMyDisasm).Operand2.Registers.fpu = REGS[0];
            (*pMyDisasm).Operand2.OpSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
  (*pMyDisasm).Operand1.Registers.type = FPU_REG;
  (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Operand1.OpSize = 80;

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DF_(PDISASM pMyDisasm)
{
  long MyMODRM;
  char (*pRegistersFPU)[8][8] ;

  GV.DECALAGE_EIP = 0;
  if (!Security(1, pMyDisasm)) {return;}
  MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
  pRegistersFPU = &RegistersFPU_Masm;
  if (GV.SYNTAX_ == NasmSyntax) {
      pRegistersFPU = &RegistersFPU_Nasm;
  }
  if (MyMODRM <= 0xbf) {

      GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
      if (GV.REGOPCODE == 0) {
          GV.MemDecoration = Arg2word;
          MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
          #endif
          (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand1.Registers.type = FPU_REG;
          (*pMyDisasm).Operand1.Registers.fpu = REG0;
          (*pMyDisasm).Operand1.OpSize = 80;
      }
      else if (GV.REGOPCODE == 1) {
          GV.MemDecoration = Arg1word;
          MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = FPU_REG;
          (*pMyDisasm).Operand2.Registers.fpu = REG0;
          (*pMyDisasm).Operand2.OpSize = 80;
      }
      else if (GV.REGOPCODE == 2) {
          GV.MemDecoration = Arg1word;
          MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fist ");
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = FPU_REG;
          (*pMyDisasm).Operand2.Registers.fpu = REG0;
          (*pMyDisasm).Operand2.OpSize = 80;
      }
      else if (GV.REGOPCODE == 3) {
          GV.MemDecoration = Arg1word;
          MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = FPU_REG;
          (*pMyDisasm).Operand2.Registers.fpu = REG0;
          (*pMyDisasm).Operand2.OpSize = 80;
      }
      else if (GV.REGOPCODE == 4) {
          GV.MemDecoration = Arg2multibytes;
          MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fbld ");
          #endif
          (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand1.Registers.type = FPU_REG;
          (*pMyDisasm).Operand1.Registers.fpu = REG0;
          (*pMyDisasm).Operand1.OpSize = 80;
      }
      else if (GV.REGOPCODE == 5) {
          GV.MemDecoration = Arg2qword;
          MOD_RM(&(*pMyDisasm).Operand2, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
          #endif
          (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand1.Registers.type = FPU_REG;
          (*pMyDisasm).Operand1.Registers.fpu = REG0;
          (*pMyDisasm).Operand1.OpSize = 80;
      }
      else if (GV.REGOPCODE == 6) {
          GV.MemDecoration = Arg1multibytes;
          MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fbstp ");
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = FPU_REG;
          (*pMyDisasm).Operand2.Registers.fpu = REG0;
          (*pMyDisasm).Operand2.OpSize = 80;
      }
      else if (GV.REGOPCODE == 7) {
          GV.MemDecoration = Arg1qword;
          MOD_RM(&(*pMyDisasm).Operand1, pMyDisasm);
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = FPU_REG;
          (*pMyDisasm).Operand2.Registers.fpu = REG0;
          (*pMyDisasm).Operand2.OpSize = 80;
      }
      else {
          FailDecode(pMyDisasm);
      }
  }
  else {
      if ((MyMODRM & 0xf0) == 0xc0) {
        if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ffreep ");
          #endif
        }
        else {
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch7 ");
          #endif
          (*pMyDisasm).Operand2.AccessMode = WRITE;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = FPU_REG;
        (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
        (*pMyDisasm).Operand1.OpSize = 80;
      }
      else if ((MyMODRM & 0xf0) == 0xd0) {
        if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp8 ");
          #endif
        }
        else {
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp9 ");
          #endif
          (*pMyDisasm).Operand2.AccessMode = WRITE;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
        #endif
        (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
        (*pMyDisasm).Operand1.Registers.type = FPU_REG;
        (*pMyDisasm).Operand1.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
        (*pMyDisasm).Operand1.OpSize = 80;

      }
      else if ((MyMODRM & 0xf0) == 0xe0) {
        if (MyMODRM == 0xe0) {
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstsw ");
          #endif
        }
        else if ((MyMODRM & 0xf) >=8) {
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomip ");
          #endif
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
          #endif
          (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand1.Registers.type = FPU_REG;
          (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
          (*pMyDisasm).Operand1.OpSize = 80;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = FPU_REG;
          (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
          (*pMyDisasm).Operand2.OpSize = 80;
        }
        else {
          FailDecode(pMyDisasm);
        }
      }

      else if ((MyMODRM & 0xf0) == 0xf0) {
        if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
          (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomip ");
          #endif
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Operand1.OpMnemonic, (*pRegistersFPU)[0]);
          #endif
          (*pMyDisasm).Operand1.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand1.Registers.type = FPU_REG;
          (*pMyDisasm).Operand1.Registers.fpu = REGS[0];
          (*pMyDisasm).Operand1.OpSize = 80;
          #ifndef BEA_LIGHT_DISASSEMBLY
             (void) strcpy ((*pMyDisasm).Operand2.OpMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
          #endif
          (*pMyDisasm).Operand2.OpType = REGISTER_TYPE;
          (*pMyDisasm).Operand2.Registers.type = FPU_REG;
          (*pMyDisasm).Operand2.Registers.fpu = REGS[(MyMODRM & 0xf)%8];
          (*pMyDisasm).Operand2.OpSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
      }
      else {
          FailDecode(pMyDisasm);
      }
  }
  GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
*      0x 0f 38 62
* ==================================================================== */
void __bea_callspec__ vpexpandb_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpexpandb ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpexpandw ");
        #endif
      }
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 63
* ==================================================================== */
void __bea_callspec__ vpcompressb_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcompressb ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcompressw ");
        #endif
      }
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      ArgsVEX_ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 64
* ==================================================================== */
void __bea_callspec__ vpblendmd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendmd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendmq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 65
* ==================================================================== */
void __bea_callspec__ vpblendmps_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendmps ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendmpd ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 66
* ==================================================================== */
void __bea_callspec__ vpblendmb_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendmb ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpblendmw ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 70
* ==================================================================== */
void __bea_callspec__ vpshldvw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshldvw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }

    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 71
* ==================================================================== */
void __bea_callspec__ vpshldvd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshldvd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshldvq ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 72
* ==================================================================== */
void __bea_callspec__ vpshrdvw_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshrdvw ");
        #endif
        GV.EVEX.tupletype = FULL_MEM;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }

  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 73
* ==================================================================== */
void __bea_callspec__ vpshrdvd_(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshrdvd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshrdvq ");
        #endif
      }
      GV.EVEX.tupletype = FULL_MEM;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }

  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*
* ==================================================================== */
void __bea_callspec__ vpermi_(PDISASM pMyDisasm, const char* mnemonic1, const char* mnemonic2, UInt8 tupletype)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic1);
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, mnemonic2);
        #endif
      }
      GV.EVEX.tupletype = tupletype;
      ArgsVEX(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*  0f 38 75
* ==================================================================== */
void __bea_callspec__ vpermi2b_(PDISASM pMyDisasm)
{
  vpermi_(pMyDisasm, "vpermi2b ", "vpermi2w ", FULL_MEM);
}

/* ====================================================================
*  0f 38 76
* ==================================================================== */
void __bea_callspec__ vpermi2d_(PDISASM pMyDisasm)
{
  vpermi_(pMyDisasm, "vpermi2d ", "vpermi2q ", FULL_MEM);
}

/* ====================================================================
*  0f 38 77
* ==================================================================== */
void __bea_callspec__ vpermi2ps_(PDISASM pMyDisasm)
{
  vpermi_(pMyDisasm, "vpermi2ps ", "vpermi2pd ", FULL_MEM);
}

/* ====================================================================
*      0x 0f 38 88
* ==================================================================== */
void __bea_callspec__ vexpandps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.EVEX.W == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vexpandpd ");
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vexpandps ");
      #endif
    }
    GV.EVEX.tupletype = TUPLE1_SCALAR;
    ArgsVEX_GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 89
* ==================================================================== */
void __bea_callspec__ vpexpandd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.EVEX.W == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpexpandq ");
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpexpandd ");
      #endif
    }
    GV.EVEX.tupletype = TUPLE1_SCALAR;
    ArgsVEX_GxEx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 8a
* ==================================================================== */
void __bea_callspec__ vcompressps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.EVEX.W == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcompresspd ");
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vcompressps ");
      #endif
    }
    GV.EVEX.tupletype = TUPLE1_SCALAR;
    ArgsVEX_ExGx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 8b
* ==================================================================== */
void __bea_callspec__ vpcompressd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.EVEX.W == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcompressq ");
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpcompressd ");
      #endif
    }
    GV.EVEX.tupletype = TUPLE1_SCALAR;
    ArgsVEX_ExGx(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 8d
* ==================================================================== */
void __bea_callspec__ vpermb(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.EVEX.W == 1) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermw ");
      #endif
    }
    else {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpermb ");
      #endif
    }
    GV.EVEX.tupletype = FULL_MEM;
    ArgsVEX(pMyDisasm);
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 8f
* ==================================================================== */
void __bea_callspec__ vpshufbitqmb(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.EVEX.W == 0) {
      #ifndef BEA_LIGHT_DISASSEMBLY
         (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpshufbitqmb ");
      #endif
      GV.EVEX.tupletype = FULL_MEM;
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      GV.Register_ = OPMASK_REG;
      Reg_Opcode(&(*pMyDisasm).Operand1, pMyDisasm);
      if (GV.VEX.L == 0) {
        GV.Register_ = SSE_REG;
        GV.MemDecoration = Arg3_m128_xmm;
      }
      else if (GV.VEX.L == 0x1) {
        GV.Register_ = AVX_REG;
        GV.MemDecoration = Arg3_m256_ymm;
      }
      else if (GV.EVEX.LL == 0x2) {
        GV.Register_ = AVX512_REG;
        GV.MemDecoration = Arg3_m512_zmm;
      }
      fillRegister((~GV.VEX.vvvv & 0xF) + 16 * GV.EVEX.V, &(*pMyDisasm).Operand2, pMyDisasm);
      MOD_RM(&(*pMyDisasm).Operand3, pMyDisasm);
      GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}
/* ====================================================================
*      0x 0f 38 83
* ==================================================================== */
void __bea_callspec__ vpmultishift(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmultishiftqb ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 A0
* ==================================================================== */

void __bea_callspec__ vpscatterdd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpscatterdd ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX512_REG;
          GV.Register_ = AVX512_REG;
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpscatterdq ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = AVX512_REG;
        }
      }
      GV.EVEX.masking = MERGING;
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      GV.MemDecoration = Arg1dword;
      ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 A1
* ==================================================================== */

void __bea_callspec__ vpscatterqd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpscatterqd ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX512_REG;
          GV.Register_ = AVX_REG;
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpscatterqq ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX512_REG;
          GV.Register_ = AVX512_REG;
        }
      }
      GV.EVEX.masking = MERGING;
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      GV.MemDecoration = Arg1qword;
      ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 A2
* ==================================================================== */

void __bea_callspec__ vpscatterdps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscatterdps ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX512_REG;
          GV.Register_ = AVX512_REG;
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscatterdpd ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = AVX512_REG;
        }
      }
      GV.EVEX.masking = MERGING;
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      GV.MemDecoration = Arg1dword;
      ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 A3
* ==================================================================== */

void __bea_callspec__ vpscatterqps(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      (*pMyDisasm).Instruction.Category = AVX512_INSTRUCTION;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscatterqps ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX512_REG;
          GV.Register_ = AVX_REG;
        }
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vscatterqpd ");
        #endif
        if (GV.VEX.L == 0) {
          GV.VSIB_ = SSE_REG;
          GV.Register_ = SSE_REG;
        }
        else if (GV.VEX.L == 0x1) {
          GV.VSIB_ = AVX_REG;
          GV.Register_ = AVX_REG;
        }
        else if (GV.EVEX.LL == 0x2) {
          GV.VSIB_ = AVX512_REG;
          GV.Register_ = AVX512_REG;
        }
      }
      GV.EVEX.masking = MERGING;
      GV.EVEX.tupletype = TUPLE1_SCALAR;
      GV.MemDecoration = Arg1qword;
      ExGx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}


/* ====================================================================
*      0x 0f 38 b4
* ==================================================================== */
void __bea_callspec__ vpmadd52luq(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmadd52luq ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 b5
* ==================================================================== */
void __bea_callspec__ vpmadd52huq(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.W == 1) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpmadd52huq ");
        #endif
        GV.EVEX.tupletype = FULL;
        ArgsVEX(pMyDisasm);
      }
      else {
        FailDecode(pMyDisasm);
      }
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}

/* ====================================================================
*      0x 0f 38 c4
* ==================================================================== */
void __bea_callspec__ vpconflictd(PDISASM pMyDisasm)
{
  if (GV.EVEX.state == InUsePrefix) {
    if (GV.VEX.pp == 1) {
      if (GV.EVEX.vvvv != 15) GV.ERROR_OPCODE = UD_;
      if (GV.EVEX.W == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpconflictd ");
        #endif
      }
      else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vpconflictq ");
        #endif
      }
      GV.EVEX.tupletype = FULL;
      ArgsVEX_GxEx(pMyDisasm);
    }
    else {
      FailDecode(pMyDisasm);
    }
  }
  else {
    FailDecode(pMyDisasm);
  }
}
