Import("env")
import shutil
import os


def copy_uf2(source, target, env):
    uf2_src = os.path.join(env.subst("$BUILD_DIR"), env.subst("${PROGNAME}.uf2"))
    uf2_dst = os.path.join(env.subst("$PROJECT_DIR"), "stepminia.uf2")
    if os.path.exists(uf2_src):
        shutil.copy2(uf2_src, uf2_dst)
        print(f"==> Copied UF2 to {uf2_dst}")
    else:
        print(f"==> UF2 not found at {uf2_src}")


env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", copy_uf2)
