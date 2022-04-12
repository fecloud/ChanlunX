package com.stock.chanlun

import com.stock.ChanlunXLib
import java.io.File
import java.nio.file.FileSystems
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.math.abs

class Main(val root:String) {

    fun readStockNames(){
        val shStockNames = Files.readAllLines(FileSystems.getDefault().getPath(root,"sh.all.csv")).map {
            val split = it.split(",")
            "${split[0]}=${split[3]}"
        }
        val szStockNames = Files.readAllLines(FileSystems.getDefault().getPath(root,"sz.all.csv")).map {
            val split = it.split(",")
            "${split[0]}=${split[3]}"
        }



        Files.write(FileSystems.getDefault().getPath("sz.properties"),szStockNames)
        Files.write(FileSystems.getDefault().getPath("sh.properties"),shStockNames)
    }

}

fun main(args: Array<String>) {

    Main("C:\\Users\\Administrator\\PycharmProjects\\untitled").readStockNames()
//
//    print(args[0])
//        val listFiles = File(args[0]).listFiles()
//
//        listFiles.forEach {
//            val h = mutableListOf<Float>()
//            val l = mutableListOf<Float>()
//            val c = mutableListOf<Float>()
//            Files.readAllLines(FileSystems.getDefault().getPath(it.absolutePath)).forEachIndexed { index, s ->
//
//                if (index > 0) {
//                    val ss = s.split(",")
//                    c.add(ss[1].toFloat())
//                    h.add(ss[2].toFloat())
//                    l.add(ss[3].toFloat())
//
//                }
//            }
//
//            val code = it.name
//            val len = h.size
//            val hf = h.toFloatArray()
//            val lf = l.toFloatArray()
//            val cout = FloatArray(len)
//            ChanlunXLib.Func2(len, cout, hf, lf, lf)
//
//            val found = cout.reversed().filterIndexed { index, f1 ->
//                abs(f1) == 1.0f && index in 2..3
//            }
//
//            if (found.isNotEmpty()) {
//                when (found.first()) {
//                    1.0f -> {
//
//                        println(
//                            "TdxJava出现顶分型$code ${c.last()}"
//                        )
//                    }
//                    -1.0f -> {
//                        println(
//                            "TdxJava出现底分型$code ${c.last()}"
//                        )
//                    }
//                }
//            }
//
//        }

}