# overo uses OMAP3 (ARM-CortexA8) cpu
#
# Physical Address:
# 8000'0000 (bank0)
# A000/0000 (bank1)
# Linux-Kernel is expected to be at 8000'8000, entry 8000'8000
# (mem base + reserved)

# For use with external or internal boots.
TEXT_BASE = 0x80e80000


