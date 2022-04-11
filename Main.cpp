#include "Main.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "com_stock_ChanlunXLib.h"

using namespace std;


//=============================================================================
// 输出函数1号：输出简笔顶底端点
//=============================================================================
void Func1(int nCount, float *pOut, float *pHigh, float *pLow, float *pIgnore)
{
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<float> out = Bi1(nCount, high, low);
    memset(pOut, 0, nCount);
    for (int i = 0; i < nCount; i++)
    {
        pOut[i] = out[i];
    }
}

//=============================================================================
// 输出函数2号：输出标准笔顶底端点
//=============================================================================
void Func2(int nCount, float *pOut, float *pHigh, float *pLow, float *pIgnore)
{
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<float> out = Bi2(nCount, high, low);
    memset(pOut, 0, nCount);

    for (int i = 0; i < nCount; i++)
    {
        pOut[i] = out[i];
        
    }

    
   
}

//=============================================================================
// 输出函数3号：输出段的端点标准画法
//=============================================================================
void Func3(int nCount, float *pOut, float *pIn, float *pHigh, float *pLow)
{
    std::vector<float> bi(pIn, pIn + nCount);
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<float> out = Duan1(nCount, bi, high, low);
    memset(pOut, 0, nCount);
    for (int i = 0; i < nCount; i++)
    {
        pOut[i] = out[i];
    }
}

//=============================================================================
// 输出函数4号：输出段的端点1+1终结画法
//=============================================================================
void Func4(int nCount, float *pOut, float *pIn, float *pHigh, float *pLow)
{
    std::vector<float> bi(pIn, pIn + nCount);
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<float> out = Duan2(nCount, bi, high, low);
    memset(pOut, 0, nCount);
    for (int i = 0; i < nCount; i++)
    {
        pOut[i] = out[i];
    }
}

//=============================================================================
// 输出函数5号：中枢高点数据
//=============================================================================
void Func5(int nCount, float *pOut, float *pIn, float *pHigh, float *pLow)
{
    std::vector<float> bi(pIn, pIn + nCount);
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<Pivot> ZhongShuList = ZS(nCount, bi, high, low);
    memset(pOut, 0, nCount);
    for (size_t i = 0; i < ZhongShuList.size(); i++)
    {
        Pivot ZhongShuOne = ZhongShuList.at(i);
        for (int j = ZhongShuOne.s + 1; j <= ZhongShuOne.e - 1; j++)
        {
            pOut[j] = ZhongShuOne.zg;
        }
    }
}

//=============================================================================
// 输出函数6号：中枢低点数据
//=============================================================================
void Func6(int nCount, float *pOut, float *pIn, float *pHigh, float *pLow)
{
    std::vector<float> bi(pIn, pIn + nCount);
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<Pivot> ZhongShuList = ZS(nCount, bi, high, low);
    memset(pOut, 0, nCount);
    for (size_t i = 0; i < ZhongShuList.size(); i++)
    {
        Pivot ZhongShuOne = ZhongShuList.at(i);
        for (int j = ZhongShuOne.s + 1; j <= ZhongShuOne.e - 1; j++)
        {
            pOut[j] = ZhongShuOne.zd;
        }
    }
}

//=============================================================================
// 输出函数7号：中枢起点、终点信号
//=============================================================================
void Func7(int nCount, float *pOut, float *pIn, float *pHigh, float *pLow)
{
    std::vector<float> bi(pIn, pIn + nCount);
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<Pivot> ZhongShuList = ZS(nCount, bi, high, low);
    memset(pOut, 0, nCount);
    for (size_t i = 0; i < ZhongShuList.size(); i++)
    {
        Pivot ZhongShuOne = ZhongShuList.at(i);
        pOut[ZhongShuOne.s + 1] = 1;
        pOut[ZhongShuOne.e - 1] = 2;
    }
}

//=============================================================================
// 输出函数8号：中枢方向数据
//=============================================================================
void Func8(int nCount, float *pOut, float *pIn, float *pHigh, float *pLow)
{
    std::vector<float> bi(pIn, pIn + nCount);
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<Pivot> ZhongShuList = ZS(nCount, bi, high, low);
    memset(pOut, 0, nCount);
    for (size_t i = 0; i < ZhongShuList.size(); i++)
    {
        Pivot ZhongShuOne = ZhongShuList.at(i);
        for (int j = ZhongShuOne.s + 1; j <= ZhongShuOne.e - 1; j++)
        {
            pOut[j] = (float)ZhongShuOne.direction;
        }
    }
}

//=============================================================================
// 输出函数9号：同方向的第几个中枢
//=============================================================================
void Func9(int nCount, float *pOut, float *pIn, float *pHigh, float *pLow)
{
    std::vector<float> bi(pIn, pIn + nCount);
    std::vector<float> high(pHigh, pHigh + nCount);
    std::vector<float> low(pLow, pLow + nCount);
    std::vector<Pivot> ZhongShuList = ZS(nCount, bi, high, low);
    memset(pOut, 0, nCount);
    for (size_t i = 0; i < ZhongShuList.size(); i++)
    {
        Pivot ZhongShuOne = ZhongShuList.at(i);
        float c = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (ZhongShuList.at(j).direction = ZhongShuList.at(i).direction)
            {
                c++;
            }
            else
            {
                break;
            }
        }
        for (int j = ZhongShuOne.s + 1; j <= ZhongShuOne.e - 1; j++)
        {
            pOut[j] = c;
        }
    }
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func1
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func1
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func1(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
    
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func2
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func2
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func2(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);

}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func3
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func3
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func3(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func4
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func4
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func4(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func5
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func5
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func5(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func6
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func6
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func6(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func7
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func7
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func7(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func8
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func8
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func8(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
}

/*
 * Class:     com_stock_ChanlunXLib
 * Method:    Func9
 * Signature: (I[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_stock_ChanlunXLib_Func9
(JNIEnv* env, jclass jcl, jint len, jfloatArray out, jfloatArray ina, jfloatArray inb, jfloatArray inc)
{
    jfloat* out_float = env->GetFloatArrayElements(out, JNI_FALSE);
    jfloat* ina_float = env->GetFloatArrayElements(ina, 0);
    jfloat* inb_float = env->GetFloatArrayElements(inb, 0);
    jfloat* inc_float = env->GetFloatArrayElements(inc, 0);
    Func9(len, out_float, ina_float, inb_float, inc_float);
    env->SetFloatArrayRegion(out, 0, len, out_float);
    env->ReleaseFloatArrayElements(out, out_float, 0);
    env->ReleaseFloatArrayElements(ina, ina_float, 0);
    env->ReleaseFloatArrayElements(inb, inb_float, 0);
    env->ReleaseFloatArrayElements(inc, inc_float, 0);
}
