import Dependencies._

ThisBuild / scalaVersion     := "2.12.8"

lazy val root = (project in file("."))
  .settings(
    name := "our_riscv_5_stage",
    libraryDependencies ++= Seq(
      "edu.berkeley.cs" %% "chisel3" % "3.4.3",
      "edu.berkeley.cs" %% "chiseltest" % "0.3.3" % Test,
      "org.scalatest" %% "scalatest" % "3.1.4" % Test
    ),
    scalacOptions ++= Seq(
      "-Xsource:2.11",
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-Xcheckinit",
      // Enables autoclonetype2 in 3.4.x (on by default in 3.5)
      "-P:chiselplugin:useBundlePlugin"
    ),
    addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % "3.4.3" cross CrossVersion.full),
    addCompilerPlugin("org.scalamacros" % "paradise" % "2.1.1" cross CrossVersion.full)
  )

