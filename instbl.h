// Header file for Instruction Table setup
// DST 2008

void *FuncIdx[296]={	InvalidCode,    ori_b,          ori_to_ccr,     ori_w,          ori_to_sr,
						ori_l,          btst_d,         bchg_d,         bclr_d,         bset_d,
						movep_w_mr,     movep_l_mr,     movep_w_rm,     movep_l_rm,     andi_b,
						andi_w,         andi_l,         andi_to_ccr,    andi_to_sr,     subi_b,
						subi_w,         subi_l,         addi_b,         addi_w,         addi_l,
						btst_s,         bchg_s,         bclr_s,         bset_s,         eori_b,
						eori_w,         eori_l,         eori_to_ccr,    eori_to_sr,     cmpi_b,
						cmpi_w,         cmpi_l,         move_b,         move_b_from_dn, move_b_to_dn,
						move_b_reg,     move_l,         move_l_from_dn, move_l_to_dn,   move_l_reg,
						movea_l,        movea_l_an,     move_w,         move_w_from_dn, move_w_to_dn,
						move_w_reg,     movea_w,        negx_b,         negx_w,         negx_l,
						move_from_sr,   chk,            lea,            clr_b,          clr_w,
						clr_l,          neg_b,          neg_w,          neg_l,          move_to_ccr,
						not_b,          not_w,          not_l,          move_to_sr,     nbcd,
						pea,            swap,           movem_save_w,   ext_w,          movem_save_l,
						ext_l,          tst_b,          tst_w,          tst_l,          tas,
						illegal,        movem_load_w,   movem_load_l,   trap,           trap0,
						trap1,          trap2,          trap3,          link,           unlk,
						move_to_usp,    move_from_usp,  reset,          nop,            stop,
						rte,            rts,            trapv,          rtr,            jsr,
						jsr_displ,      jmp,            addq_b,         addq_w,         addq_l,
						addq_an,        addq_4_an,      scc,            st,             sf,
						dbcc,           dbf,            subq_b,         subq_w,         subq_l,
						subq_an,        subq_4_an,      bcc_s,          bcc_bad,        bccc_s,
						bcs_s,          bne_s,          beq_s,          bpl_s,          bmi_s,
						bge_s,          blt_s,          bgt_s,          ble_s,          bcc_l,
						bne_l,          beq_l,          bra_s,          bra_l,          bsr,
						moveq,          or_b_dn,        or_w_dn,        or_l_dn,        or_b_ea,
						or_w_ea,        or_l_ea,        divu,           sbcd,           divs,
						sub_b_dn,       sub_w_dn,       sub_l_dn,       sub_b_ea,       sub_w_ea,
						sub_l_ea,       sub_w_an,       sub_l_an,       subx_b_r,       subx_w_r,
						subx_l_r,       subx_b_m,       subx_w_m,       subx_l_m,       cmp_b,
						cmp_w,          cmp_l,          cmp_b_dn,       cmp_b_dan,      cmp_w_dn,
						cmp_l_dn,       cmpa_w,         cmpa_l,         cmpa_l_an,      eor_b,
						eor_w,          eor_l,          cmpm_b,         cmpm_w,         cmpm_l,
						and_b_dn,       and_w_dn,       and_l_dn,       and_l_dn_dn,    and_b_ea,
						and_w_ea,       and_l_ea,       mulu,           abcd,           exg_d,
						exg_a,          exg_ad,         muls,           add_b_dn,       add_w_dn,
						add_l_dn,       add_b_dn_dn,    add_w_dn_dn,    add_l_dn_dn,    add_b_ea,
						add_w_ea,       add_l_ea,       add_w_an,       add_l_an,       add_w_an_dn,
						add_l_an_dn,    addx_b_r,       addx_w_r,       addx_l_r,       addx_b_m,
						addx_w_m,       addx_l_m,       lsr_b_i,        lsl_b_i,        lsr1_b,
						lsl1_b,         lsr_w_i,        lsl_w_i,        lsr1_w,         lsl1_w,
						lsr_l_i,        lsl_l_i,        lsr1_l,         lsl1_l,         lsl2_l,
						lsr_b_r,        lsl_b_r,        lsr_w_r,        lsl_w_r,        lsr_l_r,
						lsl_l_r,        asr_b_i,        asl_b_i,        asr_w_i,        asl_w_i,
						asr_l_i,        asl_l_i,        asr_b_r,        asl_b_r,        asr_w_r,
						asl_w_r,        asr_l_r,        asl_l_r,        roxr_b_i,       roxl_b_i,
						roxr_w_i,       roxl_w_i,       roxr_l_i,       roxl_l_i,       roxr_b_r,
						roxl_b_r,       roxr_w_r,       roxl_w_r,       roxr_l_r,       roxl_l_r,
						ror_b_i,        rol_b_i,        ror_w_i,        rol_w_i,        ror_l_i,
						rol_l_i,        ror_b_r,        rol_b_r,        ror_w_r,        rol_w_r,
						ror_l_r,        rol_l_r,        asr_m,          asl_m,          lsr_m,
						lsl_m,          roxr_m,         roxl_m,         ror_m,          rol_m,
						code1010,       InitROM,        MdvIO,          MdvOpen,        MdvClose,
						MdvSlaving,     MdvFormat,      SerIO,          SerOpen,        SerClose,
						SchedulerCmd,   DrvIO,          DrvOpen,        DrvClose,       KbdCmd,
						PollCmd,        KBencCmd,       BASEXTCmd,      devpefio_cmd,   devpefo_cmd,
						UseIPC,         ReadIPC,        WriteIPC,       FastStartup,    QL_KeyTrans,
						code1111	}

