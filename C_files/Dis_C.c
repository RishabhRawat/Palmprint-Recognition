#include "mex.h"

double calcDist(uint8_T *x, uint8_T *y, size_t xr, size_t xc, int thresh)
{
    bool *xny;
    int num, denom;
    int i,j;
    
    num = 0;
    denom = 0;
    
    xny = mxMalloc(xc*xr*sizeof(bool));
    
    for(i = 0; i < xr; i++ )
    {
        for(j = 0; j < xc; j++ )
        {
            if( x[i*xc+j] > 0 && y[i*xc+j] > 0)
            {
                xny[i*xc+j] = 1;
                denom++;
            }
            else
                xny[i*xc+j] = 0;
        }
    }
    //mexPrintf("aas [%d,%d] =  %d adsfs ",x[1*xc+2],y[1*xc+2],(x[1*xc+2])^(y[1*xc+2]));
    for(i = 0; i < xr; i++ )
    {
        for(j = 0; j < xc; j++ )
        {
            if( ((int)((x[i*xc+j])^(y[i*xc+j])) > thresh) && (xny[i*xc+j] == 1))
            {
                num++;
                //mexPrintf("as %d as ",num);
            }
        }
    }
    //mexPrintf("as %d as ",denom);
    return ((double)num)/denom;
    
}

/* The gateway function */
void mexFunction( int nlhs, mxArray *plhs[],
        int nrhs, const mxArray *prhs[])
{
    int threshold;
    
    uint8_T *inMatrixA;
    uint8_T *inMatrixB;
    
    size_t Acols,Arows,Bcols,Brows;
    
    
    /* check for proper number of arguments */
    if(nrhs!=3) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Three inputs required.");
    }
    if(nlhs!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }
    /* make sure the first input argument is scalar */
    if( !mxIsUint8(prhs[0]) ||
            mxIsComplex(prhs[0])){
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notScalar","First Image must be a 8bit greyscale.");
    }
    
    /* make sure the second input argument is type double */
    if( !mxIsUint8(prhs[1]) ||
            mxIsComplex(prhs[1])) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notDouble","Second Image must be a 8bit greyscale.");
    }
    //Third Element
    if( !mxIsDouble(prhs[2]) ||
            mxIsComplex(prhs[2]) ||
            mxGetNumberOfElements(prhs[2])!=1 ) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notScalar","Third Element must be a scalar");
    }
    
    /* get the value of the scalar input  */
    threshold = (int)mxGetScalar(prhs[2]);
    
    /* create a pointer to the real data in the input matrix  */
    inMatrixA = (uint8_T *)mxGetData(prhs[0]);
    inMatrixB = (uint8_T *)mxGetData(prhs[1]);
    
    /* get dimensions of the input matrix */
    Arows = mxGetM(prhs[0]);
    Brows = mxGetM(prhs[1]);
    
    Acols = mxGetN(prhs[0]);
    Bcols = mxGetN(prhs[1]);
    
    if(Arows != Brows || Acols != Bcols)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notEqual","Both Images must be of same size");
    }
    
    /* create the output matrix */
    plhs[0] = mxCreateDoubleScalar(calcDist(inMatrixA,inMatrixB,Arows,Acols,threshold));
}
