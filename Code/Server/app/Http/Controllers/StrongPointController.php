<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;

use App\StrongPoint;

class StrongPointController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\JsonResponse
     */
    public function index()
    {
        $strongPoints = StrongPoint::select('id', 'location_x', 'location_y')->get();

        $data = ['strongpoints' => $strongPoints];
        return response()->json($data);
    }
}
