# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

set axilite_register_dict [dict create]
set port_mul_io {
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
out_r { 
	dir O
	width 32
	depth 1
	mode ap_vld
	offset 16
	offset_end 23
}
in_r { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
}
dict set axilite_register_dict mul_io $port_mul_io


# Native S_AXILite:
if {${::AESL::PGuard_simmodel_gen}} {
	if {[info proc ::AESL_LIB_XILADAPTER::s_axilite_gen] == "::AESL_LIB_XILADAPTER::s_axilite_gen"} {
		eval "::AESL_LIB_XILADAPTER::s_axilite_gen { \
			id 1 \
			corename mul_test_mul_io_axilite \
			name mul_test_mul_io_s_axi \
			ports {$port_mul_io} \
			op interface \
			is_flushable 0 \ 
		} "
	} else {
		puts "@W \[IMPL-110\] Cannot find AXI Lite interface model in the library. Ignored generation of AXI Lite  interface for 'mul_io'"
	}
}

if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler mul_test_mul_io_s_axi
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


