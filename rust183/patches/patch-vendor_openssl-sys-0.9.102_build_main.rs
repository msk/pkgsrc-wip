$NetBSD$

Patterned after Linux and Android, on 32-bit NetBSD ports
include -latomic.  Parts of this inspired by
https://github.com/sfackler/rust-openssl/commit/a0a1d1d29263abb7c47fc2e58cef8dab13762a45

--- vendor/openssl-sys-0.9.102/build/main.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ vendor/openssl-sys-0.9.102/build/main.rs
@@ -142,6 +142,14 @@ fn main() {
         println!("cargo:rustc-link-lib=atomic");
     }
 
+    // Patterned of the above, make sure we include -latomic
+    // on ilp32 ports (yes, this only tests the "p32" part).
+    if env::var("CARGO_CFG_TARGET_OS").unwrap() == "netbsd"
+       && env::var("CARGO_CFG_TARGET_POINTER_WIDTH").unwrap() == "32"
+    {
+       println!("cargo:rustc-link-lib=atomic");
+    }
+
     if kind == "static" && target.contains("windows") {
         println!("cargo:rustc-link-lib=dylib=gdi32");
         println!("cargo:rustc-link-lib=dylib=user32");
