#include <iostream>
// #include <opencv4/opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <ceres/ceres.h>
#include <chrono>
#include <fstream>

using namespace std;

//构建代价函数
struct CURVE_FITTING_COST
{
    CURVE_FITTING_COST (double x, double y): _x(x), _y(y) {}

    template<typename T>
    bool operator()(const T* const abc, T* residual) const
    {
        residual[0]=T(_y) - ceres::exp(abc[0]*T(_x) * T(_x) + abc[1]*T(_x) +abc[2]);
        return true;
    }

    const double _x, _y;
};





int main()
{
    string fp("./data.txt");
    ofstream outfile;
    outfile.open(fp,ios::trunc);

    double a=1.0, b=2.0, c=1.0; //真实的参数
    int N=100 ;  //数据点
    double w_sigma = 1.0;
    cv::RNG rng;
    double abc[3] = {0,0,0};




    // 数据生成
    vector<double> x_data, y_data;
    cout << "gernerating data" << endl;

    for(int i=0; i<N; i++)
    {
        double x = i/100.0, y=0;
        x_data.push_back(x);
        y = exp(a*x*x+b*x+c)+rng.gaussian(w_sigma);
        y_data.push_back(y);

        outfile << x << "\t"<< y << endl;

        cout << x_data[i] << " " << y_data[i] << endl;
    }





    // 构建最小二乘问题
    ceres::Problem problem;
    for(int i=0; i<N; i++)
    {
        problem.AddResidualBlock(new ceres::AutoDiffCostFunction<CURVE_FITTING_COST, 1, 3>(new CURVE_FITTING_COST(x_data[i], y_data[i])), nullptr, abc);

    }


    //配置优化选项
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;

    ceres::Solver::Summary summary;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    ceres::Solve(options, &problem, &summary);//进行优化
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2-t1);
    cout << "solve time cost : " <<  time_used.count()  << "miliseconds" << endl;

    cout << summary.BriefReport() << endl;
    cout << "estimate a,b,c = " ;
    for(auto a:abc)cout << a<< " ";
    cout << endl;

    outfile << abc[0] << "\t"<< abc[1] <<  "\t" << abc[2] << endl;
    outfile.close();
    return 0;
}