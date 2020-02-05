# This script segment is generated automatically by AutoPilot

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


